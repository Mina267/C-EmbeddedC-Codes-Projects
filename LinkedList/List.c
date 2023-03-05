#include "list.h"


node_t* CreateNode(int data)
{
    node_t *NewNode = (node_t *)malloc(sizeof(node_t));
    NewNode->data = data;
    NewNode->next = NULL_POINTER;
    return NewNode;
}

void List_CreateNodeAtlast(node_t **phead, int data)
{
    if (*phead == NULL_POINTER)
    {
        node_t *newNode = CreateNode(data);
        newNode->next = *phead;
        *phead = newNode;
    }
    node_t *NewNode = CreateNode(data);
    node_t *current = *phead;
    while(current->next != NULL_POINTER)
    {
        current = current->next;
    }
    current->next = NewNode;
}


void List_print(node_t *head)
{
    node_t *current = head;
    while(current != NULL_POINTER)
    {
        printf("%d  ", current->data);
        current = current->next;

    }
    printf("\n====================================\n");
}


void List_printAddress(node_t *head)
{
    node_t *current = head;
    while (current != NULL_POINTER)
    {
        printf("curr = 0x%x --> %d  : / curr->next = 0x%x \n\n", current, current->data, current->next);
        current = current->next;

    }
}


void List_addNodeToFirst(node_t **phead, int data)
{
    node_t *newNode = CreateNode(data);
    newNode->next = *phead;
    *phead = newNode;

}

int  List_editNode(node_t *head, int oldData, int newData)
{
    if (head == NULL_POINTER)
    {
        return EMPTY_LIST;
    }
    node_t *current = head;
    while (current != NULL_POINTER)
    {
        if (current->data == oldData)
        {
            current->data = newData;
            return NODE_ADD;
        }
        current = current->next;
    }
    return NO_NODE;

}

int List_insertAfter(node_t *head, int prevData, int newData)
{
    if (head == NULL_POINTER)
    {
        return EMPTY_LIST;
    }
    node_t *newNode = CreateNode(newData);
    node_t *current = head;

    while (current != NULL_POINTER)
    {
        if (current->data ==prevData)
        {
            newNode->next = current->next;
            current->next = newNode;
            return NODE_ADD;
        }
        current = current->next;
    }

    return NODE_NOTFOUND;

}


int List_insertBefore(node_t *head, int prevData, int newData)
{
    if (head == NULL_POINTER)
    {
        return EMPTY_LIST;
    }
    node_t *newNode = CreateNode(newData);
    node_t *current = head;

    while(current->next != NULL_POINTER)
    {
        if (current->next->data == prevData)
        {
            newNode->next=  current->next->next;
            current->next->next = newNode;
            return NODE_ADD;
        }
        current = current->next;
    }
    return NODE_NOTFOUND;
}


int List_removeNodeMid(node_t **phead, int RemoveData)
{
    if (*phead == NULL_POINTER)
    {
        return EMPTY_LIST;
    }
    if ((*phead)->data == RemoveData)
    {
        node_t *tmp = *phead;
        *phead = (*phead)->next;
        free(tmp);
        return NODE_REMOVE;
    }
    node_t *current = *phead;
    node_t *tmp = NULL_POINTER;
    while (current->next != NULL_POINTER)
    {
        if(current->next->data == RemoveData)
        {
            tmp = current->next;
            current->next = current->next->next;
            free(tmp);
            return NODE_REMOVE;
        }
        current = current->next;
    }
    return NODE_NOTFOUND;
}



int List_removeNodeFirst(node_t **phead)
{
    if (*phead == NULL_POINTER)
    {
        return EMPTY_LIST;
    }
    node_t *tmp = *phead;
    *phead = (*phead)->next;
    free(tmp);
    return NODE_REMOVE;
}


int List_removeNodeLast(node_t **phead)
{
    node_t *current = *phead;
    if (*phead == NULL_POINTER)
    {
        return EMPTY_LIST;
    }
    if (current->next->next == NULL_POINTER)
    {
        node_t *tmp = *phead;
        *phead = (*phead)->next;
        free(tmp);
        return NODE_REMOVE;
    }
    while (current->next != NULL_POINTER)
    {
        if (current->next->next == 0)
        {
            free(current->next);
            current->next = NULL_POINTER;
            return NODE_REMOVE;
        }
        current = current->next;
    }
}

void List_printReverse(node_t *head)
{
    node_t *current = head;
    int sizeCnt;
    int size = 0;
    while(current != NULL_POINTER)
    {
        size++;
        current = current->next;
    }

    for (int NodeIndex = FIRSTNODE; NodeIndex < size; NodeIndex++)
    {
        current = head;
        sizeCnt = size - 1 - NodeIndex;
        while(sizeCnt)
        {
            current = current->next;
            sizeCnt--;
        }
        printf("%d  ", current->data);
    }

}



