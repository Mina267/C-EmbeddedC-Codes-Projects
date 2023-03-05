#include "DynamicStack.h"

StackCtreateStatus_t Stack_Create(int StackSize, stack_t *ps)
{
    ps->pti = (int *)malloc(StackSize * sizeof(int));

    if (ps->pti == NULL)
    {
        return STACK_FAIL;
    }
    ps->size = StackSize;
    ps->SP = STACK_START;

    return STACK_CREATED;
}


void Stack_Delete(stack_t *ps)
{
    free(ps->pti);
    ps->pti = NULL;
    ps->size = NULL;
    ps->SP = NULL;
}


StackStatus_type Stack_push(stack_t *ps, int data)
{
    StackStatus_type Status;
    if (ps->pti == NULL)
    {
        return NO_STACK;
    }

    if (ps->SP == ps->size)
    {
        Status = STACK_FULL;
    }
    else
    {
        ps->pti[ps->SP] = data;
        ps->SP++;
        Status = STACK_PUSHED;
    }
    return Status;
}

StackStatus_type Stack_pop(stack_t *ps, int *data)
{
    StackStatus_type Status;
    if (ps->pti == NULL)
    {
        return NO_STACK;
    }

    if (ps->SP == 0)
    {
        Status = STACK_EMPTY;
    }
    else
    {
        (ps->SP)--;
        *data = ps->pti[ps->SP];
        Status = STACK_POP;
    }
    return Status;
}

