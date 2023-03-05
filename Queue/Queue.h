#ifndef Queue_H_

#define Queue_H_

#define QUEUE_SIZE      5
#define IN_START        0
#define OUT_START       0
#define QPTR_INC        1
#define NO_DATA         0


typedef enum{
    Q_EMPTY,
    Q_FULL = 0,
    Q_DONE,
}queue_status_t;

queue_status_t inQueue(int data);
queue_status_t deQueue(int *pdata);


#endif // Queue_H_
