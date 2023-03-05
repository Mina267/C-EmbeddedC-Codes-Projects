#ifndef List_H_
#define List_H_

#define NULL_POINTER    0
#define EMPTY_LIST      0
#define NODE_ADD        1
#define NODE_REMOVE     1
#define NO_NODE         0
#define NODE_NOTFOUND   0
#define FIRSTNODE       0

typedef struct node{
    int data;
    struct node *next;
}node_t;


node_t* CreateNode(int data);
void List_CreateNodeAtlast(node_t **phead, int data);
void List_addNodeToFirst(node_t **phead, int data);
void List_print(node_t *head);
int  List_editNode(node_t *head, int oldData, int newData);
int List_insertAfter(node_t *head, int prevData, int newData);
int List_insertBefore(node_t *phead, int prevData, int newData);
int List_removeNodeMid(node_t **phead, int data);
int List_removeNodeFirst(node_t **phead);
int List_removeNodeLast(node_t **phead);
void List_printReverse(node_t *head);


#endif // List_H_
