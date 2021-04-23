/**********************************************
        CS415  Project 2
        Spring  2021
        Student Version
**********************************************/

#ifndef ATTR_H
#define ATTR_H

typedef union {int num; char *str;} tokentype;

typedef enum type_expression {TYPE_INT=0, TYPE_BOOL, TYPE_ERROR} Type_Expression;

typedef enum var_Type { TYPE_SCALAR=0, TYPE_ARRAY } Var_Type;

typedef struct {
        Type_Expression type;
        int targetRegister;
        } regInfo;

// My Declarations
typedef struct varNode {
        char* name;
        struct varNode *next;
} varNode;

typedef struct varList {
        varNode *head;
} varList;

typedef struct fstmt {
        int decLabel;
        int trueLabel;
        int falseLabel;
} fstmt;

typedef struct cntrlExp{
        char* indexStr;
        int upperBoundReg;
} cntrlExp;

typedef struct ifStmtType{
        int trueLabel;
        int falseLabel;
} ifStmtType;

typedef struct ifHeadType{
        int trueLabel;
        int falseLabel;
        int followLabel;
} ifHeadType;

typedef struct condExp{
        int targetReg;
} condExp;

typedef struct type{
        Type_Expression baseType;
        Var_Type varType;
        int varSize;
} type;

void varList_insert(varList *list, char* var);
void varList_printList(varList *list);


#endif


  
