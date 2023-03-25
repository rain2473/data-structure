// 리스트 자체를 구현하는 코드
// arraylist.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// element.h을 include -> 요소가 리스트에 포함되므로, 요소의 특성과 성질을 알고 있어야함.
#include "arraylist.h"

// 리스트의 요소를 출력 한줄에 10개 씩
void print_list(arraylist *list)
{
	for (int i = 0; i < list->size; ++i)
	{
		printf("%02s ", to_str(list->array[i]));
		if (i % 10 == 9)
			printf("\n");
	}
	printf("\n");
}
// 리스트의 맨 뒤에 요소를 더해줌
void append_list(arraylist *list, element value)
{
	// printf("값 %02s를 리스트 맨 끝에 추가합니다.\n", to_str(value));
	list->array[list->size++] = value;
}
// 리스트의 중간에 요소를 삽입함
void insert_list(arraylist *list, int index, element value)
{
	// printf("값 %02s를 %0d 번째에 삽입합니다.\n", to_str(value), index);
	for (int k = list->size - 1; k >= index; k--)
		list->array[k + 1] = list->array[k];
	list->array[index] = value;
	list->size++;
}
// 리스트의 요소를 삭제함
element delete_list(arraylist *list, int index)
{
	element result = list->array[index];
	for (int k = index; k < list->size - 1; k++)
		list->array[k] = list->array[k + 1];
	// printf("%02d 번째 값을 삭제합니다. 값 = %02s\n", index, to_str(result));
	list->size--;
	return result;
}
// 특정 위치의 리스트의 요소를 수정함
element update_list(arraylist *list, int index, element value)
{
	element result = list->array[index];
	list->array[index] = value;
	// printf("%02d 번째 값을 %02s로 변경합니다. 이전값 = %02s\n",
	index, to_str(value), to_str(result);
	return result;
}
// 리스트의 특정 위치의 요소를 반환함 -> 인덱싱 -> 지금 이건 배열이 아닌 리스트이므로, 배열식 인덱싱 (adsf[i]) 안됨
element get(arraylist *list, int index)
{
	return list->array[index];
}
// 특정 요소의 리스트 내의 위치를 반환함 -> 검색(유무)
int index(arraylist *list, element value)
{
	for (int i = 0; i < list->size; i++)
	{
		if (compare(list->array[i], value) == 0)
			return i; // 찾고자 하는 요소의 인덱스를 반환함
	}
	return -1; // 찾고자 하는 요소가 리스트에 없는 경우 -1을 반환함
}
// 리스트의 요소의 갯수 반환
int len(arraylist *list)
{
	return list->size;
}
// 리스트의 크기를 0으로 초기화함
void init_list(arraylist *list)
{
	list->size = 0;
}
// 리스트의 모든 요소를 제거해서 리스트를 비움
void clear(arraylist *list)
{
	for (int i = 0; i < list->size; i++)
		free_element(list->array[i]);
	list->size = 0;
}
// 리스트에 n개의 요소를 입력받는다 -> 리스트 간 합을 구현시 사용가능
void add_list(arraylist *list, int n)
{
	list->size = n;
	for (int i = 0; i < list->size; ++i)
	{
		list->array[i] = new_element();
	}
}
// 리스트에 할당된 메모리를 해제한다. -> 완전삭제
void free_list(arraylist *list)
{
	clear(list);
}