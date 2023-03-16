// 리스트 자체를 구현하는 코드
// arllist.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// elem.h을 include -> 요소가 리스트에 포함되므로, 요소의 특성과 성질을 알고 있어야함.
#include "arrlist.h"

// 리스트의 요소를 출력 한줄에 8개 씩
void print_list(arrlist_t* lp) {
	for (int i = 0; i < lp->size; ++i) {
		printf("%2s ", str(lp->array[i]));
		if (i % 8 == 7)
			printf("\n");
	}
	printf("\n");
}
// 리스트의 맨 뒤에 요소를 더해줌
void add_list(arrlist_t* lp, elem_t val) {
	printf("값 %2s를 리스트 맨 끝에 추가합니다.\n", str(val));
	lp->array[lp->size++] = val;
}
// 리스트의 중간에 요소를 삽입함
void insert_list(arrlist_t* lp, int pos, elem_t val) {
	printf("값 %2s를 %d 번째에 삽입합니다.\n", str(val), pos);
	for (int k = lp->size - 1; k >= pos; k--)
		lp->array[k + 1] = lp->array[k];
	lp->array[pos] = val;
	lp->size++;
}
// 리스트의 요소를 삭제함
elem_t delete_list(arrlist_t* lp, int pos) {
	elem_t result = lp->array[pos];
	for (int k = pos; k < lp->size - 1; k++)
		lp->array[k] = lp->array[k + 1];
	printf("%2d 번째 값을 삭제합니다. 값 = %s\n", pos, str(result));
	lp->size--;
	return result;
}
// 특정 위치의 리스트의 요소를 수정함
elem_t update_list(arrlist_t* lp, int pos, elem_t val) {
	elem_t result = lp->array[pos];
	lp->array[pos] = val;
	printf("%2d 번째 값을 %2s로 변경합니다. 이전값 = %s\n", 
		pos, str(val), str(result));
	return result;
}
// 리스트의 특정 위치의 요소를 반환함 -> 인덱싱 -> 지금 이건 배열이 아닌 리스트이므로, 배열식 인덱싱 (adsf[i]) 안됨
elem_t get(arrlist_t* lp, int index) {
	return lp->array[index];
}
// 특정 요소의 리스트 내의 위치를 반환함 -> 검색(유무)
int find(arrlist_t* lp, elem_t val) {
	for (int i = 0; i < lp->size; i++) {
		if (compare(lp->array[i], val) == 0)
			return i; // 찾고자 하는 요소의 인덱스를 반환함
	}
	return -1; // 찾고자 하는 요소가 리스트에 없는 경우 -1을 반환함
}
// 리스트의 요소의 갯수 반환
int len(arrlist_t* lp) {
	return lp->size;
}
// 리스트의 크기를 0으로 초기화함
void init_list(arrlist_t* lp) {
	lp->size = 0;
}
// 리스트의 모든 요소를 제거해서 리스트를 비움
void clear(arrlist_t* lp) {
	for (int i = 0; i < lp->size; i++)
		free_elem(lp->array[i]);
	lp->size = 0;
}
// 리스트에 n개의 요소를 입력받는다 -> 리스트 간 합을 구현시 사용가능
void input_list(arrlist_t* lp, int sz) {
	lp->size = sz;
	for (int i = 0; i < lp->size; ++i) {
		lp->array[i] = get_next();
	}
}
// 리스트에 할당된 메모리를 해제한다. -> 완전삭제
void free_list(arrlist_t* lp) {
	clear(lp);
}