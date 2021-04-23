/**********************************************
        CS415  Project 2
        Spring  2021
        Student Version
**********************************************/

#ifndef ATTR_H
#define ATTR_H

typedef union {int num; char *str;} tokentype;

typedef enum type_expression {TYPE_INT=0, TYPE_BOOL, TYPE_ERROR} Type_Expression;

typedef struct {
        Type_Expression type;
        int targetRegister;
        } regInfo;

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

void varList_insert(varList *list, char* var);
void varList_printList(varList *list);


#endif


  
