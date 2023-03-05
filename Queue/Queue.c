#include "Queue.h"

/*FIFO: First in first out*/

static int arr[QUEUE_SIZE];
static int queue_in  = IN_START;
static int queue_out = OUT_START;
static int Data_cnt;

queue_status_t inQueue(int data)
{
    queue_status_t status;
    if (Data_cnt == QUEUE_SIZE)
    {
        status = Q_FULL;
    }
    else
    {
        arr[queue_in] = data;
        queue_in = (queue_in + QPTR_INC) % QUEUE_SIZE;
        Data_cnt++;
        status = Q_DONE;
    }
    return status;
}

queue_status_t deQueue(int *pdata)
{
    queue_status_t status;
    if (Data_cnt == NO_DATA)
    {
        status = Q_EMPTY;
    }
    else
    {
        *pdata = arr[queue_out];
        queue_out = (queue_out + QPTR_INC) % QUEUE_SIZE;
        Data_cnt--;
        status = Q_DONE;
    }
    return status;
}

