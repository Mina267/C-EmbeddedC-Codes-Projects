#ifndef DoubleList_H_
#define DoubleList_H_


#define NULL_POINTER    ((void*)0)
#define FIRSTNODE       0
#define EMPTY_CNT       0
#define EMPTY_SIZE      0


typedef struct Dnode
{
    int data;
    struct Dnode *next;
    struct Dnode *prev;
    int size;
} Dnode_t;

typedef struct Dlist
{
    Dnode_t *head;
    Dnode_t *tail;
    int size;
} Dlist_t;

typedef Dlist_t* LIST;

typedef enum
{
    NO_DNODE,
    DNODE_NOTFOUND,
    NO_SPACE,
    EMPTY_DLIST = 0,
    DNODE_ADD,
    DNODE_REMOVE,
    DNODE_EDITED = 1,
}Dlist_status_t;

Dlist_t* Create_DoubleList(void);
Dnode_t* Create_DNode(int data);
Dlist_status_t DList_Create_DNodeAtlast(Dlist_t* Dlist, int data);
Dlist_status_t DList_addNodeToFirst(Dlist_t* Dlist, int data);
void DList_print(Dlist_t* Dlist);
void DList_printReverse(Dlist_t* Dlist);
Dlist_status_t DList_editNode(Dlist_t* Dlist, int oldData, int newData);
Dlist_status_t DList_insertAfter(Dlist_t* Dlist, int prevData, int newData);
Dlist_status_t DList_insertBefore(Dlist_t* Dlist, int prevData, int newData);
Dlist_status_t DList_remove_NodeMid(Dlist_t* Dlist, int data);
Dlist_status_t DList_remove_NodeFirst(Dlist_t* Dlist);
Dlist_status_t DList_remove_NodeLast(Dlist_t* Dlist);


#endif // DoubleList_H_
