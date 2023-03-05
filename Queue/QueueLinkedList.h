#ifndef QueueLinkedList_H_
#define QueueLinkedList_H_

#define NULL_POINTER    ((void*)0)
#define MAX_QUEUENODES  5
#define ONE_NODE        1

typedef enum{
QUEUEEMPTY,
QUEUEFULL = 0,
INQUEUE,
DEQUEUE = 1,
}QueueStatus_type;

typedef struct stacknode{
    int data;
    struct stacknode *next;
}QueueNode_t;


QueueNode_t* createQueueNewNode(int data);
QueueStatus_type in_Queue(int data);
QueueStatus_type de_Queue(int *data);
int List_QueueRemoveNodeFirst(void);
int List_QueueRemoveNodeLast(void);


#endif // QueueLinkedList_H_

