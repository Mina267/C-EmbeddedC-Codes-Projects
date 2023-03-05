#include "DoubleList.h"

Dlist_t* Create_DoubleList(void)
{
    Dlist_t *Doublelist = (Dlist_t*) malloc(sizeof(Dlist_t));
    Doublelist->head = NULL_POINTER;
    Doublelist->tail = NULL_POINTER;
    Doublelist->size = 0;
    return Doublelist;
}

Dnode_t* Create_DNode(int data)
{
    Dnode_t *newNode = (Dnode_t*) malloc(sizeof(Dnode_t));
    newNode->data = data;
    newNode->next = NULL_POINTER;
    newNode->prev = NULL_POINTER;
    newNode->size = EMPTY_CNT;
    return newNode;
}

Dlist_status_t DList_Create_DNodeAtlast(Dlist_t* Dlist, int data)
{
    Dnode_t *newNode = Create_DNode(data);

    if (newNode == NULL_POINTER)
    {
        return NO_SPACE;
    }

    if (Dlist->tail == NULL_POINTER)
    {
        Dlist->head = newNode;
        Dlist->tail = newNode;
        Dlist->size++;
    }
    else
    {
        Dlist->tail->next = newNode;
        Dlist->tail->next->prev = Dlist->tail;
        Dlist->tail = newNode;
        Dlist->size++;
    }

    return DNODE_ADD;

}

Dlist_status_t DList_addNodeToFirst(Dlist_t* Dlist, int data)
{
    Dnode_t *newNode = Create_DNode(data);
    if (newNode == NULL_POINTER)
    {
        return NO_SPACE;
    }
    if (Dlist->head == NULL_POINTER)
    {
        Dlist->head = newNode;
        Dlist->tail = newNode;
        Dlist->size++;
    }
    else
    {
        newNode->next = Dlist->head;
        Dlist->head->prev = newNode;
        Dlist->head = newNode;
        Dlist->size++;
    }
    return DNODE_ADD;
}

void DList_print(Dlist_t* Dlist)
{
    Dnode_t *current = Dlist->head;
    while (current != 0)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n====================================\n");
}

void DList_printReverse(Dlist_t* Dlist)
{
    Dnode_t *current = Dlist->tail;
    while (current != NULL_POINTER)
    {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n====================================\n");
}

Dlist_status_t DList_editNode(Dlist_t* Dlist, int oldData, int newData)
{
    Dnode_t *current = Dlist->head;
    while (current != NULL_POINTER)
    {
        if (current->data == oldData)
        {
            current->data = newData;
            return DNODE_EDITED;
        }
        current = current->next;
    }
    return DNODE_NOTFOUND;

}

Dlist_status_t DList_insertAfter(Dlist_t* Dlist, int prevData, int newData)
{
    if (Dlist->head == NULL_POINTER)
    {
        return EMPTY_DLIST;
    }

    Dnode_t *newNode = Create_DNode(newData);
    Dnode_t *current = Dlist->head;

    if(Dlist->tail->data == prevData)
    {
        newNode->prev = Dlist->tail;
        Dlist->tail->next = newNode;
        Dlist->tail = newNode;
        Dlist->size++;
        return DNODE_ADD;
    }

    while (current != NULL_POINTER)
    {
        if (current->data == prevData)
        {
            newNode->next = current->next;
            current->next->prev = newNode;
            newNode->prev = current;
            current->next = newNode;
            Dlist->size++;
            return DNODE_ADD;
        }
        current = current->next;
    }
    return DNODE_NOTFOUND;


}

Dlist_status_t DList_insertBefore(Dlist_t* Dlist, int prevData, int newData)
{
    if (Dlist->size == EMPTY_SIZE)
    {
        return EMPTY_DLIST;
    }

    Dnode_t *newNode = Create_DNode(newData);
    Dnode_t *current = Dlist->head;

    if(Dlist->head->data == prevData)
    {
        newNode->next = Dlist->head;
        Dlist->head->prev = newNode;
        Dlist->head = newNode;
        Dlist->size++;
        return DNODE_ADD;
    }

    while (current != NULL_POINTER)
    {
        if (current->data == prevData)
        {
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newData;
            newNode->next = current;
            Dlist->size++;
            return DNODE_ADD;
        }
        current = current->next;
    }
    return DNODE_NOTFOUND;

}


Dlist_status_t DList_remove_NodeFirst(Dlist_t* Dlist)
{
    if (Dlist->size == 0)
    {
        return EMPTY_DLIST;
    }
    else if (Dlist->head == Dlist->tail)
    {
        free(Dlist->head);
        Dlist->head = NULL_POINTER;
        Dlist->tail = NULL_POINTER;
        Dlist->size--;
        return DNODE_REMOVE;
    }
    else
    {
        Dnode_t *tmp = Dlist->head;
        Dlist->head->next->prev = NULL_POINTER;
        Dlist->head = Dlist->head->next;
        Dlist->size--;
        free(tmp);
        return DNODE_REMOVE;
    }
}

Dlist_status_t DList_remove_NodeLast(Dlist_t* Dlist)
{
    if (Dlist->size == 0)
    {
        return EMPTY_DLIST;
    }
    else if (Dlist->head == Dlist->tail)
    {
        free(Dlist->head);
        Dlist->head = NULL_POINTER;
        Dlist->tail = NULL_POINTER;
        Dlist->size--;
        return DNODE_REMOVE;

    }
    else
    {
        Dnode_t *tmp = Dlist->tail;
        Dlist->tail->prev->next = NULL_POINTER;
        Dlist->tail = Dlist->tail->prev;
        Dlist->size--;
        free(tmp);
        return DNODE_REMOVE;
    }
}

Dlist_status_t DList_remove_NodeMid(Dlist_t* Dlist, int data)
{
    if (Dlist->size == 0)
    {
        return EMPTY_DLIST;
    }

    else if(Dlist->head->data == data)
    {
        DList_remove_NodeFirst(Dlist);
        return DNODE_REMOVE;
    }
    else if(Dlist->tail->data == data)
    {
        DList_remove_NodeLast(Dlist);
        return DNODE_REMOVE;
    }
    else
    {
        Dnode_t *current = Dlist->head;
        while(current!= NULL_POINTER)
        {
            if (current->data == data)
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                Dlist->size--;
                free(current);
                return DNODE_REMOVE;
            }
            current = current->next;
        }
    }
     return DNODE_NOTFOUND;
}



