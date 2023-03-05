#ifndef QueueDoubleList_H_
#define QueueDoubleList_H_


#define MAX_QUEUENODES  5
#define ONE_NODE        1
#define NULL_POINTER    ((void*)0)
#define FIRSTNODE       0
#define EMPTY_CNT       0
#define EMPTY_SIZE      0
#define NO_NODE         0


typedef struct Dnode
{
    int data;
    struct Dnode *next;
    struct Dnode *prev;
    int size;
} QueueDnode_t;

typedef struct Dlist
{
    QueueDnode_t *head;
    QueueDnode_t *tail;
    int size;
} QueueDlist_t;

typedef QueueDlist_t* LIST;


typedef enum
{
    QUEUE_EMPTY = 0,
    QUEUE_FULL = 0,
    IN_QUEUE = 1,
    DE_QUEUE = 1,
} QueueDlistStatus_type;


QueueDnode_t* createNewNode(int data);
QueueDlistStatus_type inQueue_DList(int data);
QueueDlistStatus_type deQueue_DList(int *data);
int DList_QueueRemoveNodeFirst(void);
int DList_QueueRemoveNodeLast(void);

#endif // QueueDoubleList_H_
