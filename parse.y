%{
#include <stdio.h>
#include "attr.h"
#include "instrutil.h"
int yylex();
void yyerror(char * s);
#include "symtab.h"

FILE *outfile;
char *CommentBuffer;
 
%}

%union {tokentype token;
        regInfo targetReg;

        // My declarations
        varList *vList;
        Type_Expression tex;
       }

%token PROG PERIOD VAR 
%token INT BOOL PRT THEN IF DO FI ENDFOR
%token ARRAY OF 
%token BEG END ASG  
%token EQ NEQ LT LEQ GT GEQ AND OR TRUE FALSE
%token ELSE
%token FOR 
%token <token> ID ICONST 

%type <targetReg> exp 
%type <targetReg> lhs 
// My Type Declarations
%type <vList> idlist
%type <tex> stype
%type <tex> type

%start program

%nonassoc EQ NEQ LT LEQ GT GEQ 
%left '+' '-' AND
%left '*' OR

%nonassoc THEN
%nonassoc ELSE

%%
program : {emitComment("Assign STATIC_AREA_ADDRESS to register \"r0\"");
           emit(NOLABEL, LOADI, STATIC_AREA_ADDRESS, 0, EMPTY);} 
           PROG ID ';' block PERIOD { printf("\n\n Done with compiling program \"%s\"\n ", $3.str); }
	;

block	: variables cmpdstmt { }
	;

variables: /* empty */
	| VAR vardcls { }
	;

vardcls	: vardcls vardcl ';' { }
	| vardcl ';' { }
	| error ';' { yyerror("***Error: illegal variable declaration\n");}  
	;

vardcl	: idlist ':' type { 
                varNode* ptr = $1->head;
                while(ptr != NULL){
                        insert(ptr->name, $3, NextOffset(1));
                        ptr = ptr->next;
                }

        }
	;

idlist	: idlist ',' ID { printf("Running idlist \"%s\" ", $3.str); 
                                varList_insert($1, $3.str);
                                varList_printList($1);
                                $$ = $1;
                        }
        | ID		{ printf("Running idlist \"%s\" ", $1.str);
                                varList* list = malloc(sizeof(varList));
                                list->head = NULL;
                                varList_insert(list, $1.str);
                                
                                printf("\nAdding Node: \"%s\"\n", list->head->name);
                                $$ = list;
                         } 
	;


type	: ARRAY '[' ICONST ']' OF stype {  }

        | stype {  }
	;

stype	: INT { 
                $$ = TYPE_INT;
        }
        | BOOL { 
                $$ = TYPE_BOOL; 
        }
	;

stmtlist : stmtlist ';' stmt { }
	| stmt { }
        | error { yyerror("***Error: ';' expected or illegal statement \n");}
	;

stmt    : ifstmt { }
	| fstmt { }
	| astmt { }
	| writestmt { }
	| cmpdstmt { }
	;

cmpdstmt: BEG stmtlist END { }
	;

ifstmt :  ifhead 
          THEN
          stmt 
  	  ELSE 
          stmt 
          FI
	;

ifhead : IF condexp {  }
        ;

writestmt: PRT '(' exp ')' { int printOffset = -4; /* default location for printing */
  	                         sprintf(CommentBuffer, "Code for \"PRINT\" from offset %d", printOffset);
	                         emitComment(CommentBuffer);
                                 emit(NOLABEL, STOREAI, $3.targetRegister, 0, printOffset);
                                 emit(NOLABEL, 
                                      OUTPUTAI, 
                                      0,
                                      printOffset, 
                                      EMPTY);
                               }
	;

fstmt	: FOR ctrlexp DO stmt { }
          ENDFOR
	;



astmt : lhs ASG exp             { 
 				  if (! ((($1.type == TYPE_INT) && ($3.type == TYPE_INT)) || 
				         (($1.type == TYPE_BOOL) && ($3.type == TYPE_BOOL)))) {
				    printf("*** ERROR ***: Assignment types do not match.\n");
				  }

				  emit(NOLABEL,
                                       STORE, 
                                       $3.targetRegister,
                                       $1.targetRegister,
                                       EMPTY);
                                }
	;

lhs	: ID			{ /* BOGUS  - needs to be fixed */
                                  int newReg1 = NextRegister();
                                  int newReg2 = NextRegister();
                                  int offset = lookup($1.str) != NULL ? lookup($1.str)->offset : NextOffset(1);

                                  sprintf(CommentBuffer, "Compute address of variable \"%s\" at offset %d in register %d", $1.str, offset, newReg2);
	                         emitComment(CommentBuffer);
				  
                                  $$.targetRegister = newReg2;

                                  $$.type = lookup($1.str)->type;

                                  if(lookup($1.str) == NULL){
				        insert($1.str, TYPE_INT, offset);
                                  } 
				   
				  emit(NOLABEL, LOADI, offset, newReg1, EMPTY);
				  emit(NOLABEL, ADD, 0, newReg1, newReg2);
				  
                         	  }


                                |  ID '[' exp ']' {   }
                                ;


exp	: exp '+' exp		{ int newReg = NextRegister();

                                  if (! (($1.type == TYPE_INT) && ($3.type == TYPE_INT))) {
    				    printf("*** ERROR ***: Operator types must be integer.\n");
                                  }
                                  $$.type = $1.type;

                                  $$.targetRegister = newReg;
                                  emit(NOLABEL, 
                                       ADD, 
                                       $1.targetRegister, 
                                       $3.targetRegister, 
                                       newReg);
                                }

        | exp '-' exp		{ int newReg = NextRegister();
                                        if(! (($1.type == TYPE_INT) && ($3.type == TYPE_INT))) {
                                          printf("\n***Error: types of operands for operation '-' do not match\n");
                                        }

                                        $$.type = $1.type;

                                        $$.targetRegister = newReg;
                                        emit(NOLABEL, 
                                                SUB, 
                                                $1.targetRegister, 
                                                $3.targetRegister, 
                                                newReg);
                                 }

        | exp '*' exp		{  }

        | exp AND exp		{ int newReg = NextRegister();

                                  if (! (($1.type == TYPE_BOOL) && ($3.type == TYPE_BOOL))){
    				    printf("*** ERROR ***: Operator types must be Boolean.\n");
                                  }
                                  $$.type = $1.type;

                                  $$.targetRegister = newReg;
                                  emit(NOLABEL, 
                                       AND_INSTR, 
                                       $1.targetRegister, 
                                       $3.targetRegister, 
                                       newReg); 
                                } 


        | exp OR exp       	{ int newReg = NextRegister();

                                  if (! (($1.type == TYPE_BOOL) && ($3.type == TYPE_BOOL))) {
    				    printf("*** ERROR ***: Operator types must be Boolean.\n");
                                  }
                                  $$.type = $1.type;

                                  $$.targetRegister = newReg;
                                  emit(NOLABEL, 
                                       OR_INSTR, 
                                       $1.targetRegister, 
                                       $3.targetRegister, 
                                       newReg); 
                                }


        | ID			{ /* BOGUS  - needs to be fixed */
	                          int newReg = NextRegister();
                                  
                                  if( lookup($1.str) == NULL){
                                        printf("\n***Error: undeclared identifier \"%s\"\n", $1.str);
                                  } 

                                  int offset = lookup($1.str) != NULL ? lookup($1.str)->offset : NextOffset(1);
                                  
                                  sprintf(CommentBuffer, "Load RHS value of variable \"%s\" at offset %d", $1.str, offset);
	                         emitComment(CommentBuffer);

	                          $$.targetRegister = newReg;
                                  $$.type = lookup($1.str)->type;
				//   $$.type = TYPE_INT;

				  emit(NOLABEL, LOADAI, 0, offset, newReg);
                                  
	                        }

        | ID '[' exp ']'	{   }
 


	| ICONST                 { int newReg = NextRegister();
	                           $$.targetRegister = newReg;
				   $$.type = TYPE_INT;
				   emit(NOLABEL, LOADI, $1.num, newReg, EMPTY); }

        | TRUE                   { int newReg = NextRegister(); /* TRUE is encoded as value '1' */
	                           $$.targetRegister = newReg;
				   $$.type = TYPE_BOOL;
				   emit(NOLABEL, LOADI, 1, newReg, EMPTY); }

        | FALSE                   { int newReg = NextRegister(); /* TRUE is encoded as value '0' */
	                           $$.targetRegister = newReg;
				   $$.type = TYPE_BOOL;
				   emit(NOLABEL, LOADI, 0, newReg, EMPTY); }

	| error { yyerror("***Error: illegal expression\n");}  
	;


ctrlexp	: ID ASG ICONST ',' ICONST { }
        ;

condexp	: exp NEQ exp		{  } 

        | exp EQ exp		{  } 

        | exp LT exp		{  }

        | exp LEQ exp		{  }

	| exp GT exp		{  }

	| exp GEQ exp		{  }

	| error { yyerror("***Error: illegal conditional expression\n");}  
        ;

%%

void yyerror(char* s) {
        fprintf(stderr,"%s\n",s);
        }


int
main(int argc, char* argv[]) {

  printf("\n     CS415 Spring 2021 Compiler\n\n");

  outfile = fopen("iloc.out", "w");
  if (outfile == NULL) { 
    printf("ERROR: Cannot open output file \"iloc.out\".\n");
    return -1;
  }

  CommentBuffer = (char *) malloc(1832);  
  InitSymbolTable();

  printf("1\t");
  yyparse();
  printf("\n");

  PrintSymbolTable();
  
  fclose(outfile);
  
  return 1;
}




