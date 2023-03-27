#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
// 스택의 맨 뒤에 요소 삽입
void push(stack* s, element e) {
	if (full(s)) {
		fprintf(stderr, "재고가 꽉 찼습니다.\n");
		return;
	}
	s->data[(s->top)++] = e;
}
// 스택의 맨 뒤에서 요소 꺼냄
element pop(stack* s) {
	if (empty(s)) {
		fprintf(stderr, "재고가 바닥났습니다.\n");
		exit(1);
	}
	return s->data[--(s->top)];
}
// 스택이 비워졌는지 여부
int empty(stack* s) {
	return (s->top == 0);
}
// 스택이 꽉찼는지 여부
int full(stack* s) {
	return (s->top == MAX_STACK_SIZE);
}
// 스택을 초기화
void init(stack* s) {
	s->top = 0;
	for (int i = 0; i < MAX_STACK_SIZE; i++)
		s->data[i] = 0;
}
// 스택을 전체 출력
void print(stack* s) {
	for (int i = 0; i < s->top; i++)
		printf("%4s", to_string(s->data[i]));
	for (int i = s->top; i < MAX_STACK_SIZE; i++)
		printf("%4s", " ");
	printf("\n");
}
// 스택에 할당된 메모리를 해제
void free_stack(stack* s)
{
	for (int i = 0; i < s->top; i++) 
		free_element(s->data[i]);
	s->top = 0;
}
