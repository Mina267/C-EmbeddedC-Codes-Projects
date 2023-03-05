#ifndef StackLinkedList_H_
#define StackLinkedList_H_


#define NULL_POINTER    0
#define MAX_NUMOFNODES  5


typedef struct stacknode{
    int data;
    struct stacknode *next;
}StackNode_t;

typedef enum{
STACKSTART = 0,
STACKEMPTY = 0 ,
STACKFULL = 0,
STACKPOP = 1,
STACKPUSHED = 1,
}ListStackStatus_type;

ListStackStatus_type StackPush(int data);
ListStackStatus_type StackPop(int *data);
int List_StackRemoveNodeFirst(void);

#endif // StackLinkedList_H_
