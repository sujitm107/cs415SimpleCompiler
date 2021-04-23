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
        type type;

        fstmt forstmt;
        cntrlExp controlStmt;
        condExp conditionStmt;
        ifStmtType ifStmt;
        ifHeadType ifHead;
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
%type <type> type
%type <forstmt> FOR
%type <controlStmt> ctrlexp
%type <conditionStmt> condexp
%type <ifStmt> IF
%type <ifHead> ifhead

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
                        insert(ptr->name, $3.baseType, NextOffset($3.varSize), $3.varType);
                        // NextOffset($3.varSize - 1); //allocate space for entire array if necessary, if it is scalar, the line is negated by the -1 as the scalar's varSize is 1
                        ptr = ptr->next;
                }

        }
	;

idlist	: idlist ',' ID {     varList_insert($1, $3.str);
                                // varList_printList($1);
                                $$ = $1;
                        }
        | ID		{varList* list = malloc(sizeof(varList));
                                list->head = NULL;
                                varList_insert(list, $1.str);
                                $$ = list;
                         } 
	;


type	: ARRAY '[' ICONST ']' OF stype { $$.varType = TYPE_ARRAY; $$.baseType = $6; $$.varSize = $3.num;}

        | stype { $$.varType = TYPE_SCALAR; $$.baseType = $1; $$.varSize = 1;}
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

ifstmt :  ifhead { $1.followLabel = NextLabel(); }
          THEN {/* NEXTLABEL() L0 */ emit($1.trueLabel, NOP, EMPTY, EMPTY, EMPTY);
                sprintf(CommentBuffer, "This is the \"true\" Branch");
                emitComment(CommentBuffer);
          }
          stmt {/* GO TO BRANCH AFTER ELSE STMT */ 
                sprintf(CommentBuffer, "Branch to statement following the \"else\" statement list");
                emitComment(CommentBuffer);
                emit(NOLABEL, BR, $1.followLabel, EMPTY, EMPTY);
          }
  	  ELSE {/* NEXTLABEL() L1 */ emit($1.falseLabel, NOP, EMPTY, EMPTY, EMPTY); 
                sprintf(CommentBuffer, "This is the \"false\" Branch");
                emitComment(CommentBuffer);
            }
          stmt 
          FI {/*NEXTLABEL() L2 */ emit($1.followLabel, NOP, EMPTY, EMPTY, EMPTY);} 
	;

ifhead : IF {
                //Declare Labels
                int trueLabel = NextLabel();
                int falseLabel = NextLabel();

                $1.trueLabel = trueLabel;
                $1.falseLabel = falseLabel;

        } 
        condexp { /*DEPENING ON TARGETREG INFO CBR TO TRUE LABEL OR FALSE LABEL */


                        emit(NOLABEL, CBR, $3.targetReg, $1.trueLabel, $1.falseLabel);
                        $$.trueLabel = $1.trueLabel;
                        $$.falseLabel = $1.falseLabel;
                }
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

fstmt	: FOR {
                sprintf(CommentBuffer, "Control For \"FOR\" Statement"); emitComment(CommentBuffer); 

                // Regiseters 7 8 should be declared here?

                int decLabel = NextLabel();
                int trueLabel = NextLabel();
                int falseLabel = NextLabel();

                $1.decLabel = decLabel;
                $1.trueLabel = trueLabel;
                $1.falseLabel = falseLabel;

        } ctrlexp { 
                
                int offset = lookup($3.indexStr)->offset; //Swap with offset of i which is saved in ctrlexp
                int newReg = NextRegister(); 
                int upperBoundReg = $3.upperBoundReg; // NextRegister(); //Swap with Ctrl Upper
                int decLabel = $1.decLabel; //Swap with For Dec Label
                emit(decLabel, LOADAI, 0, offset, newReg);

                int newReg2 = NextRegister();
                emit(NOLABEL, CMPLE, newReg, upperBoundReg, newReg2);

                int trueLabel = $1.trueLabel; // Swap with For True Label
                int falseLabel = $1.falseLabel; // Swap with For False Label

                emit(NOLABEL, CBR, newReg2, trueLabel, falseLabel);
        }
        DO {emit($1.trueLabel, NOP, EMPTY, EMPTY, EMPTY);} 
        stmt { 
                int currIndexReg = NextRegister();
                int newIndexReg = NextRegister();

                //Incrementing I
                int offset = lookup($3.indexStr)->offset; // offset of i
                emit(NOLABEL, LOADAI, 0, offset, currIndexReg);
                emit(NOLABEL, ADDI, currIndexReg, 1, newIndexReg);
                emit(NOLABEL, STOREAI, newIndexReg, 0, offset);
                emit(NOLABEL, BR, $1.decLabel, EMPTY, EMPTY);
         }
          ENDFOR {emit($1.falseLabel, NOP, EMPTY, EMPTY, EMPTY);}
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

                                  sprintf(CommentBuffer, "Compute address of variable \"%s\" with base address %d", $1.str, offset);
	                         emitComment(CommentBuffer);
				  
                                  $$.targetRegister = newReg2;
                                  $$.type = lookup($1.str)->type;

                                  if(lookup($1.str) == NULL){
				        insert($1.str, TYPE_INT, offset, TYPE_SCALAR);
                                  } 
				   
				  emit(NOLABEL, LOADI, offset, newReg1, EMPTY);
				  emit(NOLABEL, ADD, 0, newReg1, newReg2);
				  
                         	  }


                                |  ID '[' exp ']' { 
                                        
                                        int base_address = lookup($1.str)->offset;
                                        sprintf(CommentBuffer, "Compute address of array \"%s\" with base address %d", $1.str, base_address);

                                        emitComment(CommentBuffer);

                                        //Store final value in here
                                        int final_reg = NextRegister();

                                        // Load Constant 4 into a register
                                        int four_reg = NextRegister();
                                        emit(NOLABEL, LOADI, 4, four_reg, EMPTY);

                                        // Get register the index is stored in [exp]
                                        int constant_reg = $3.targetRegister;

                                        // Compute the total offset by multilying the index * 4
                                        int mult_offset_reg = NextRegister();
                                        emit(NOLABEL, MULT, constant_reg, four_reg, mult_offset_reg);
                                        
                                        //Load Base address
                                        int base_addr_reg = NextRegister();
                                        emit(NOLABEL, LOADI, base_address, base_addr_reg, EMPTY);

                                        //Compute Total Offset by adding mult_offset and base address
                                        int total_addr_reg = NextRegister();
                                        emit(NOLABEL, ADD, base_addr_reg, mult_offset_reg, total_addr_reg);

                                        //add total offset to base addr r0(1024) to get actual value
                                        emit(NOLABEL, ADD, 0, total_addr_reg, final_reg);

                                        $$.targetRegister = final_reg;
                                        $$.type = lookup($1.str)->type;
         

                                  }
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

        | exp '*' exp		{ int newReg = NextRegister();
                                        if(! (($1.type == TYPE_INT) && ($3.type == TYPE_INT))) {
                                          printf("\n***Error: types of operands for operation '-' do not match\n");
                                        }

                                        $$.type = $1.type;

                                        $$.targetRegister = newReg;
                                        emit(NOLABEL, 
                                                MULT, 
                                                $1.targetRegister, 
                                                $3.targetRegister, 
                                                newReg); 
                                }

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

        | ID '[' exp ']'	{  
                                        int base_address = lookup($1.str)->offset;
                                        sprintf(CommentBuffer, "Load RHS value of array variable \"%s\" with base address %d", $1.str, base_address);

                                        emitComment(CommentBuffer);

                                        //Store final value in here
                                        int final_reg = NextRegister();

                                        // Load Constant 4 into a register
                                        int four_reg = NextRegister();
                                        emit(NOLABEL, LOADI, 4, four_reg, EMPTY);

                                        // Get register the index is stored in [exp]
                                        int constant_reg = $3.targetRegister;

                                        // Compute the total offset by multilying the index * 4
                                        int mult_offset_reg = NextRegister();
                                        emit(NOLABEL, MULT, constant_reg, four_reg, mult_offset_reg);
                                        
                                        //Load Base address
                                        int base_addr_reg = NextRegister();
                                        emit(NOLABEL, LOADI, base_address, base_addr_reg, EMPTY);

                                        //Compute Total Offset by adding mult_offset and base address
                                        int total_addr_reg = NextRegister();
                                        emit(NOLABEL, ADD, base_addr_reg, mult_offset_reg, total_addr_reg);

                                        //add total offset to base addr r0(1024) to get actual value
                                        emit(NOLABEL, LOADAO, 0, total_addr_reg, final_reg);

                                        $$.targetRegister = final_reg;
                                        $$.type = lookup($1.str)->type;

                                }
 


	| ICONST                 { int newReg = NextRegister();
	                           $$.targetRegister = newReg;
				   $$.type = TYPE_INT;
				   emit(NOLABEL, LOADI, $1.num, newReg, EMPTY); }

        | TRUE                   { int newReg = NextRegister(); /* TRUE is encoded as value '1' */
	                           $$.targetRegister = newReg;
				   $$.type = TYPE_BOOL;
				   emit(NOLABEL, LOADI, 1, newReg, EMPTY); }

        | FALSE                   { int newReg = NextRegister(); /* FALSE is encoded as value '0' */
	                           $$.targetRegister = newReg;
				   $$.type = TYPE_BOOL;
				   emit(NOLABEL, LOADI, 0, newReg, EMPTY); }

	| error { yyerror("***Error: illegal expression\n");}  
	;


ctrlexp	: ID ASG ICONST ',' ICONST { 
                                sprintf(CommentBuffer, "Initialize ind. variable \"%s\" at offset X with lower bound value %d", $1.str, $3);
                                emitComment(CommentBuffer); 

                                int offset = lookup($1.str) != NULL ? lookup($1.str)->offset : NextOffset(1);
                                int newReg = NextRegister(); //offset of i
                                emit(NOLABEL, LOADI, offset, newReg, EMPTY);

                                int memReg = NextRegister(); //mem addr for i
                                emit(NOLABEL, ADD, 0, newReg, memReg);

                                // Load In start and end bound
                                int start = $3.num;
                                int end = $5.num;
                                
                                int startReg = NextRegister();
                                int endReg = NextRegister();

                                emit(NOLABEL, LOADI, start, startReg, EMPTY);
                                emit(NOLABEL, LOADI, end, endReg, EMPTY);

                                emit(NOLABEL, STORE, startReg, memReg, EMPTY);

                                $$.indexStr = $1.str;
                                $$.upperBoundReg = endReg;
        
                        }
        ;

condexp	: exp NEQ exp		{  } 

        | exp EQ exp		{  } 

        | exp LT exp		{//MUST BE INTEGERS
                                        int newReg = NextRegister();
                                        emit(NOLABEL, CMPLT, $1.targetRegister, $3.targetRegister, newReg);

                                        $$.targetReg = newReg;
                                 }

        | exp LEQ exp		{ //MUST BE INTEGERS
                                        int newReg = NextRegister();
                                        emit(NOLABEL, CMPLE, $1.targetRegister, $3.targetRegister, newReg);

                                        $$.targetReg = newReg; }

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




