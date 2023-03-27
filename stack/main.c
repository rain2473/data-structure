// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "stack.h"

int total_input = 0;
int total_output = 0;

//입고 함수
void receive(stack* s, element e){
    if (total_input - total_output + e > MAX_STACK_SIZE) {
	fprintf(stderr, "재고가 꽉 찼습니다.\n 다시 입력해주세요.\n");
	}
    else{
        push(s, e);
        total_input += e;
        if (total_input - total_output == MAX_STACK_SIZE)
        {
            fprintf(stderr, "재고가 꽉 찼습니다.\n");
        }
    }
}

//출고 함수
void release(stack* s, element e){
    if(e > total_input - total_output){
        fprintf(stderr, "출고가 재고보다 크므로 불가능합니다.\n 다시 입력해주세요.\n");
    }
    else{
        int tmp = pop(s);
    while(1){
    if (tmp - e >= 0){
        tmp -= e;
        break;
    }else{
        e = e - tmp;
        total_output += tmp;
        tmp = pop(s);
    }
    }
    total_output += e;
    push(s, tmp);}
    if (total_input - total_output == 0) {
		fprintf(stderr, "재고가 바닥났습니다.\n");
	}
}

//상태 출력 함수
void print_stat(stack* s){
    printf("총입고: %d ", total_input);
    printf("총출고: %d ", total_output);
    printf("재고: %d\n", total_input - total_output);
}

void run_menu(stack* sp) {
int menu, count;
while (1) {
    printf("(1) 입고 (2) 출고 (3) 종료... ");
    scanf_s("%d", &menu);
    if (menu == 1) {
        printf("입고 개수: ");
        scanf_s("%d", &count);
        receive(sp, count);
        }
    else if (menu == 2) {
        printf("출고 개수: ");
        scanf_s("%d", &count);
        release(sp, count);
        }
    else break;
    print_stat(sp);
    }
}

int main(void)
{
stack s;
init(&s);
run_menu(&s);
}