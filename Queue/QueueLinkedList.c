#include "QueueLinkedList.h"

static QueueNode_t *head = NULL_POINTER;
static QueueNode_t **phead = &head;
static int nodeCnt;
static int(*Ptf[2])(void) = {List_QueueRemoveNodeFirst, List_QueueRemoveNodeLast};

QueueNode_t* createQueueNewNode(int data)
{
    QueueNode_t *NewNode = (QueueNode_t *)malloc(sizeof(QueueNode_t));
    NewNode->data = data;
    NewNode->next = NULL_POINTER;
    return NewNode;
}


QueueStatus_type in_Queue(int data)
{
    if (nodeCnt == MAX_QUEUENODES)
    {
        return QUEUEFULL;
    }
    else
    {
        QueueNode_t *NewNode = createNewNode(data);
        NewNode->next = head;
        *phead = NewNode;
        nodeCnt++;
        return INQUEUE;
    }
}

QueueStatus_type de_Queue(int *data)
{
    if (head == NULL_POINTER)
    {
        return QUEUEEMPTY;
    }
    else
    {
        if (nodeCnt == ONE_NODE)
        {
            *data = Ptf[0]();
            nodeCnt--;
            return DEQUEUE;
        }
        else
        {
            *data = Ptf[1]();
            nodeCnt--;
            return DEQUEUE;
        }

    }
}


int List_QueueRemoveNodeFirst(void)
{
    int result;
    QueueNode_t *tmp = *phead;
    *phead = (*phead)->next;
    result = tmp->data;
    free(tmp);
    return result;
}


int List_QueueRemoveNodeLast(void)
{
    int result;
    QueueNode_t *current = head;

    while (current->next != NULL_POINTER)
    {
        if (current->next->next == NULL_POINTER)
        {
            result = current->next->data;
            free(current->next);
            current->next = NULL_POINTER;
            return result;
        }
        current = current->next;
    }
}



