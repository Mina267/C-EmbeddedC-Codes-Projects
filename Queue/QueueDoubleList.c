#include "QueueDoubleList.h"

static int nodeCnt;
static QueueDlist_t list1;
static QueueDlist_t* Dlist = &list1;


QueueDnode_t* createNewNode(int data)
{
    QueueDnode_t *newNode = (QueueDnode_t*) malloc(sizeof(QueueDnode_t));
    newNode->data = data;
    newNode->next = NULL_POINTER;
    newNode->prev = NULL_POINTER;
    newNode->size = EMPTY_CNT;
    return newNode;
}

QueueDlistStatus_type inQueue_DList(int data)
{
    //printf("size = %d\n", Dlist->size);
    if (Dlist->size == MAX_QUEUENODES)
    {
        return QUEUE_FULL;
    }
    else
    {
        QueueDnode_t *newNode = Create_DNode(data);
        if (Dlist->size == NO_NODE)
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
        return IN_QUEUE;
    }
}

QueueDlistStatus_type deQueue_DList(int *data)
{
    if (Dlist->head == NULL_POINTER)
    {
        return QUEUE_EMPTY;
    }
    else
    {
        if (Dlist->size == ONE_NODE)
        {
            *data = Dlist->head->data;
            free(Dlist->head);
            Dlist->head = NULL_POINTER;
            Dlist->tail = NULL_POINTER;
            Dlist->size--;
        }
        else
        {
            *data = Dlist->tail->data;
            QueueDnode_t *tmp = Dlist->tail;
            Dlist->tail->prev->next = NULL_POINTER;
            Dlist->tail = Dlist->tail->prev;
            Dlist->size--;
            free(tmp);
        }
        return DE_QUEUE;

    }
}
