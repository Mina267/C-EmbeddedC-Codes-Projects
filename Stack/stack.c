#include "stack.h"


static arr[STACK_SIZE];
int stack_p = STACK_START;

int push (int data)
{
    if (stack_p == STACK_SIZE)
    {
        return STACK_FULL;
    }
    else
    {
        arr[stack_p] = data;
        stack_p++;
        return STACK_PUSHED;
    }
}

int pop(int *data)
{
    if (stack_p == 0)
    {
        return STACK_EMPTY;
    }
    else
    {
        stack_p--;
        *data = arr[stack_p];
        return STACK_POP;
    }
}

