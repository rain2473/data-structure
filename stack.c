#include <stdio.h>
#include <stdlib.h>
#include <window.h>

typedef struct stack
{
    int top;
    int *data;
    int max;
}stack;

void initStack(stack *S, int size)
{
    S->data = (int *) malloc(size * sizeof(int));
    S->top = -1;
    S->max = size;
}

int Top(stack *S)
{
    if (S->top != -1)
        return (S->data[S->top]);
}

int full(stack *S)
{
    if (S->top == S->max - 1)
        return (1);
    return (0);
}

int empty(stack *S)
{
    if (S->top == -1)
        return (1);
    return (0);
}

void push(stack *S, int data)
{
    if (!full(S))
    {
        S->top++;
        S->data[S->top] = data;
    }
    else
    {
        S->data = (int *) realloc(S->data, S->max * 2 * sizeof(int));
        push(S, data);
    }
}

int pop(stack *S)
{
    int value;

    if (!empty(S))
    {
        value = S->data[S->top];
        S->top--;
        return (value);
    }
    return (0);
}

void printStack(stack *S)
{
    if (!empty(S))
    {
        int i;

        i = 0;
        while (i <= S->top)
        {
            printf("%d", S->data[i]);
            if(i != S->top)
                printf(", ");
            i++;
        }
    }
}