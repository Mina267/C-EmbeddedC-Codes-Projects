#ifndef DynamicStack_H_
#define DynamicStack_H_

#define NULL 0

typedef enum
{
    STACK_FAIL,
    STACK_CREATED,
} StackCtreateStatus_t;

typedef enum
{
    STACK_START = 0,
    STACK_EMPTY = 0,
    STACK_FULL = 0,
    STACK_POP = 1,
    STACK_PUSHED = 1,
    NO_STACK = -1,
} StackStatus_type;

typedef struct
{
    int *pti;
    int size;
    int SP;
} stack_t;

StackCtreateStatus_t Stack_Create(int StackSize, stack_t *ps);
void Stack_Delete(stack_t *ps);
StackStatus_type Stack_push(stack_t *ps, int data);
StackStatus_type Stack_pop(stack_t *ps, int *data);



#endif // DynamicStack_H_
