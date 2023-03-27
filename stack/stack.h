#pragma once
#include "element.h"
#define MAX_STACK_SIZE 50
typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} stack;
void push(stack* s, element e);
element pop(stack* s);
int empty(stack* s);
int full(stack* s);
void init(stack* s);
void print(stack* s);
void clear(stack* s);