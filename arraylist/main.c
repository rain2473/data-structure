// 리스트를 선언해서 핸들링하여 결과를 확인하는 메인 코드
// main.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 리스트를 사용하기 위해 앞서 만든 리스트 코드를 가져와야함.
#include "arraylist.h"

// lp가 가리키는 리스트에 e와 같은 값이 있으면 1, 없으면 0
int contains(arraylist *list, element e)
{
	// 리스트에서 요소가 있는지 탐색하는 함수를 써야함 -> find
	if (index(list, e) == -1)
		return 0;
	return 1;
}

// lp가 가진 요소를 중복없이 새로운 리스트(new_list)에 추가해서 돌려준다
arraylist *remove_redundancy(arraylist *list)
{
	// 새로운 리스트 new_list 선언함
	arraylist *new_list = (arraylist *)malloc(sizeof(arraylist));
	// 새로운 리스트의 크기를 0으로 초기화함
	init_list(new_list);
	// 리스트의 크기만큼 반복
	for (int i = 0; i < list->size; i++)
	{
		// 인덱스로 리스트의 요소를 꺼내야함 -> get
		int tmp = get(list, i);
		// 해당 요소가 이미 새로운 리스트에 있는지 확인해야함 -> contains
		int det = contains(new_list, tmp);
		// 만약 요소가 들어 있지 않다면 새로운 리스트에 추가한다.
		if (det == 0)
		{
			// 새로운 리스트에 추가한다. -> add_list
			append_list(new_list, tmp);
		}
		// 만약 요소가 들어 있다면, pass한다.
	}
	return new_list;
}

// 두 리스트의 교집합을 가지는 리스트를 만들어 반환한다
arraylist *compute_subset(arraylist *aptr, arraylist *bptr)
{
	arraylist *new_list = (arraylist *)malloc(sizeof(arraylist));
	init_list(new_list);
	// aptr의 요소 값들을 각각 contains로 bptr에 있는지 확인한다. -> for, get ->contains
	for (int i = 0; i < aptr->size; i++)
	{
		// 인덱스로 리스트의 요소를 꺼내야함 -> get
		int tmp = get(aptr, i);
		// tmp가 bptr에 있는지 확인한다. -> contains
		int det = contains(bptr, tmp);
		// 만약 판단 결과, 있다면, new_list에 저장한다. ->add_list
		if (det == 1)
			append_list(new_list, tmp);
		// 없으면 pass
	}
	new_list = remove_redundancy(new_list);
	return new_list;
}

// bptr가 가진 요소를 모두 aptr가 가리키는 리스트에 모두 추가한다.
void copy_list(arraylist *aptr, arraylist *bptr)
{
	// bptr이 가진 요소를 파악해서 변수에 저장한다. -> for문으로 get함수를 쓴다.
	for (int i = 0; i < bptr->size; i++)
	{
		// 인덱스로 리스트의 요소를 꺼내야함 -> get
		int tmp = get(bptr, i);
		// bptr이 가진 요소를 aptr에 추가한다. -> 맨 뒤에 넣는다. -> add_list를 사용한다.
		append_list(aptr, tmp);
	}
}

// 두 리스트의 합집합을 가지는 리스트를 만들어 반환한다
arraylist *compute_superset(arraylist *aptr, arraylist *bptr)
{
	arraylist *new_list = (arraylist *)malloc(sizeof(arraylist));
	init_list(new_list);
	for (int i = 0; i < aptr->size; i++)
	{
		// 인덱스로 리스트의 요소를 꺼내야함 -> get
		int tmp = get(aptr, i);
		// tmp가 bptr에 있는지 확인한다. -> contains
		int det = contains(bptr, tmp);
		// 만약 판단 결과, 없다면, new_list에 저장한다. ->add_list
		if (det == 0)
			append_list(new_list, tmp);
		// 있으면 pass
		// 지금까지 순수하게 리스트 a에만 있는 요소가 들어갔음 -> 리스트 b만 넣어주면 됨.
	}
	copy_list(new_list, bptr);
	new_list = remove_redundancy(new_list);
	return new_list;
}

void main()
{
	// 리스트 a와 b를 선언함
	arraylist lista, listb;
	// 리스트 a를 초기화함 (size = 0)
	init_list(&lista);
	// 리스트 a에 20개의 요소를 입력받는다. 입력은 get_next를 통해 받는다. -> 난수 20개가 저장됨
	add_list(&lista, 20);
	// 리스트 b를 초기화함 (size = 0)
	init_list(&listb);
	// 리스트 b에 20개의 요소를 입력받는다. 입력은 get_next를 통해 받는다. -> 난수 20개가 저장됨
	add_list(&listb, 20);
	// 리스트 a에 저장된 난수들을 출력함
	printf("lista: \n");
	print_list(&lista);
	// 리스트 b에 저장된 난수들을 출력함
	printf("listb: \n");
	print_list(&listb);
	// 리스트a가 가진 요소를 중복없이 새로운 리스트에 추가해서 돌려준다 -> 리스트를 셋으로 변환함
	arraylist *aptr = remove_redundancy(&lista);
	// 리스트b가 가진 요소를 중복없이 새로운 리스트에 추가해서 돌려준다 -> 리스트를 셋으로 변환함
	arraylist *bptr = remove_redundancy(&listb);
	// 셋으로 변환한 (중복을 제거한) 리스트 a를 출력한다.
	printf("lista 중복제거: \n");
	print_list(aptr);
	// 셋으로 변환한 (중복을 제거한) 리스트 b를 출력한다.
	printf("listb 중복제거: \n");
	print_list(bptr);
	// 두 리스트 a,b의 교집합을 가지는 리스트를 만들어 반환한다
	arraylist *subset = compute_subset(&lista, &listb);
	// 두 리스트 a,b의 교집합을 출력한다.
	printf("교집합: \n");
	print_list(subset);
	// 두 리스트 a,b의 합집합을 가지는 리스트를 만들어 반환한다
	arraylist *superset = compute_superset(&lista, &listb);
	// 두 리스트 a,b의 합집합을 출력한다.
	printf("합집합: \n");
	print_list(superset);
}