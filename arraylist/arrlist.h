// 리스트 자체를 정의하는 코드
// arrlist.h
#pragma once
// elem.h을 include -> 요소가 리스트에 포함되므로, 요소의 특성과 성질을 알고 있어야함.
#include "elem.h"

// arrlist_t, 리스트 구조체를 선언
typedef struct {
    // elem_t 리스트 -> 최대 100
	elem_t array[100];
    // int형의 사이즈 변수 있음 -> len에서 사용
	int size;
} arrlist_t;

// 리스트의 요소를 출력 한줄에 8개 씩
void print_list(arrlist_t* lp);
// 리스트의 맨 뒤에 요소를 더해줌
void add_list(arrlist_t* lp, elem_t val);
// 리스트의 중간에 요소를 삽입함
void insert_list(arrlist_t* lp, int pos, elem_t val);
// 리스트의 요소를 삭제함
elem_t delete_list(arrlist_t* lp, int pos);
// 특정 위치의 리스트의 요소를 수정함
elem_t update_list(arrlist_t* lp, int pos, elem_t val);
// 리스트의 특정 위치의 요소를 반환함 -> 인덱싱 -> 지금 이건 배열이 아닌 리스트이므로, 배열식 인덱싱 (adsf[i]) 안됨
elem_t get(arrlist_t* lp, int index);
// 특정 요소의 리스트 내의 위치를 반환함 -> 검색(유무)
int find(arrlist_t* lp, elem_t val);
// 리스트의 요소의 갯수 반환
int len(arrlist_t* lp);
// 리스트의 크기를 0으로 초기화함
void init_list(arrlist_t* lp);
// 리스트의 모든 요소를 제거해서 리스트를 비움
void clear(arrlist_t* lp);
// 리스트에 n개의 요소를 입력받는다 -> 리스트 간 합을 구현시 사용가능
void input_list(arrlist_t* lp, int sz);
// 리스트에 할당된 메모리를 해제한다. -> 완전삭제
void free_list(arrlist_t* lp);
