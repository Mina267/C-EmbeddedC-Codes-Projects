#include "StackLinkedList.h"

static StackNode_t *head = NULL_POINTER;
static StackNode_t **phead = &head;
static int nodeCnt;


StackNode_t* CreateNewNode(int data)
{
    StackNode_t *NewNode = (StackNode_t *)malloc(sizeof(StackNode_t));
    NewNode->data = data;
    NewNode->next = 0;
    return NewNode;
}


ListStackStatus_type StackPush(int data)
{
    if (nodeCnt == MAX_NUMOFNODES)
    {
        return STACKFULL;
    }
    else
    {
        StackNode_t *NewNode = CreateNewNode(data);
        NewNode->next = head;
        *phead = NewNode;
        nodeCnt++;
        return STACKPUSHED;
    }
}

ListStackStatus_type StackPop(int *data)
{
    if (head == NULL_POINTER)
    {
        return STACKEMPTY;
    }
    else
    {
        *data = List_StackRemoveNodeFirst();
        nodeCnt--;
        return STACKPOP;
    }
}

int List_StackRemoveNodeFirst(void)
{
    int result;
    StackNode_t *tmp = *phead;
    *phead = (*phead)->next;
    result = tmp->data;
    free(tmp);
    return result;
}




