#include <stdlib.h>
#include <windows.h>

typedef struct queue
{
    int front;
    int rear;
    int *data;
    int max;
    int cnt;
}queue;

void initQueue(queue *q, int size);
int empty(queue *q);
int full(queue *q);
int peek(queue *q);
void qExpand(queue *q);
void enqueue(queue *q, int data);
int dequeue(queue *q);

void initQueue(queue *q, int size)
{
    q->data = (int *) malloc(size * sizeof(int));
    if (!q->data)
        return ;
    q->front = size - 1;
    q->rear = size - 1;
    q->max = size;
    q->cnt = 0;
}

int empty(queue *q)
{
    if (q->rear == q->front)
        return (1);
    return (0);
}

int full(queue *q)
{
    if ((q->rear + 1) % q->max == q->front)
        return (1);
    return (0);
}

int peek(queue *q)
{
    int first_data;

    first_data = (q->front + 1) % q->max;
    if (!empty(q))
        return (q->data[first_data]);
}

void qExpand(queue *q)
{
    int i;
    int count;
    int *buf;

    buf = (int *) malloc(q->max * sizeof(int));
    count = q->cnt;
    i = 0;
    while (i < count)
    {
        buf[i] = dequeue(q);
        i++;
    }
    q->max *= 2;
    q->data = (int *) realloc(q->data, q->max * sizeof(int));
    if (!q->data)
        return ;
    initQueue(q, q->max);
    i = 0;
    while (i < count)
    {
        enqueue(q, buf[i]);
        i++;
    }
    free(buf);
}

void enqueue(queue *q, int data)
{
    if (!full(q))
    {
        q->rear = (q->rear + 1) % q->max;
        q->data[q->rear] = data;
        q->cnt++;
    }
    else
    {
        qExpand(q);
        enqueue(q, data);
    }
}

int dequeue(queue *q)
{
    if (!empty(q))
    {
        q->front = (q->front + 1) % q->max;
        q->cnt--;
        return (q->data[q->front]);
    }
}