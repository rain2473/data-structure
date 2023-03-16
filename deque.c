#include <stdio.h>
#include <stdlib.h>
#include <window.h>

typedef struct queue
{
    int front;
    int rear;
    int *data;
    int max;
    int cnt;
}queue;

void qExpand(queue *q);
void push_front(queue *q, int data);
int pop_front(queue *q);
void push_back(queue *q, int data);
int pop_back(queue *q);

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

int front(queue *q)
{
    int first_data;

    first_data = (q->front + 1) % q->max;
    if (!empty(q))
        return (q->data[first_data]);
    return (-1);
}

int back(queue *q)
{
    if (!empty(q))
        return (q->data[q->rear]);
    return (-1);
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
        buf[i] = pop_front(q);
        i++;
    }
    q->max *= 2;
    q->data = (int *) realloc(q->data, q->max * sizeof(int));
    if (!q->data)
        return ;
    count = q->cnt;
    i = 0;
    while (i < count)
    {
        push_front(q, buf[i]);
        i++;
    }
    free(buf);
}

void push_front(queue *q, int data)
{
    if (!full(q))
    {
        q->data[q->front] = data;
        q->front = (q->front - 1 + q->max) % q->max;
        q->cnt++;
    }
    else
    {
        qExpand(q);
        push_front(q, data);
    }
}

//기존 원형큐
int pop_front(queue *q)
{
    if (!empty(q))
    {
        q->front = (q->front + 1) % q->max;
        q->cnt--;
        return (q->data[q->front]);
    }
    return (-1);
}

//기존 원형큐
void push_back(queue *q, int data)
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
        push_back(q, data);
    }
}

int pop_back(queue *q)
{
    int value;

    if (!empty(q))
    {
        value = q->rear;
        q->rear = (q->rear - 1 + q->max) % q->max;
        q->cnt--;
        return (q->data[value]);
    }
    return (-1);
}