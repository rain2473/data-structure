// 리스트 자체를 정의하는 코드
// arraylist.h
#pragma once
// element.h을 include -> 요소가 리스트에 포함되므로, 요소의 특성과 성질을 알고 있어야함.
#include "element.h"

// arrlist, 리스트 구조체를 선언
typedef struct
{
    // element 리스트 -> 최대 100
    element array[100];
    // int형의 사이즈 변수 있음 -> len에서 사용 -> 요소의 갯수
    int size;
} arraylist;

// 리스트의 요소를 출력 한줄에 10개 씩
void print_list(arraylist *list);
// 리스트의 맨 뒤에 요소를 더해줌
void append_list(arraylist *list, element value);
// 리스트의 중간에 요소를 삽입함
void insert_list(arraylist *list, int index, element vvalueal);
// 리스트의 요소를 삭제함
element delete_list(arraylist *list, int index);
// 특정 위치의 리스트의 요소를 수정함
element update_list(arraylist *list, int index, element value);
// 리스트의 특정 위치의 요소를 반환함 -> 인덱싱 -> 지금 이건 배열이 아닌 리스트이므로, 배열식 인덱싱 (adsf[i]) 안됨
element get(arraylist *list, int index);
// 특정 요소의 리스트 내의 위치를 반환함 -> 검색(유무)
int index(arraylist *list, element value);
// 리스트의 요소의 갯수 반환
int len(arraylist *list);
// 리스트의 크기를 0으로 초기화함
void init_list(arraylist *list);
// 리스트의 모든 요소를 제거해서 리스트를 비움
void clear(arraylist *list);
// 리스트에 n개의 요소를 입력받는다 -> 리스트 간 합을 구현시 사용가능
void add_list(arraylist *list, int n);
// 리스트에 할당된 메모리를 해제한다. -> 완전삭제
void free_list(arraylist *llist);
