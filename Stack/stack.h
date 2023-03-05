#ifndef stack_H_
#define stack_H_
/* LIFO: last in first out */

#define STACK_SIZE   10

#define STACK_FULL   0
#define STACK_PUSHED 1
#define STACK_POP    1
#define STACK_EMPTY  0
#define STACK_START  0

int pop(int *data);
int push (int data);

#endif // stack_H_
