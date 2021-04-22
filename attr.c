/**********************************************
        CS415  Project 2
        Spring  2021
        Student Version
**********************************************/

#include "attr.h" 
#include <stdlib.h>

void varList_insert(varList *list, char *var){

        //Create Node
        varNode* newVar = malloc(sizeof(varNode));
        newVar->name = var;

        //Putting the new node at the front of the list
        newVar->next = list->head;
        list->head = newVar;
}

void varList_printList(varList *list){

        printf("\n");
        varNode * ptr = list->head;

        while(ptr != NULL){
                printf("\"%s\" -> ", ptr->name);
                ptr = ptr->next;
        }

        printf("\n");

}
