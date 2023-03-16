#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// elem_t, 리스트의 요소 구조체 -> 정수형, 숫자만 저장하는 정수 리스트임.
typedef int elem_t;

// 다음 요소를 생성함
elem_t get_next() {
    // 0 ~ 100까지 난수 생성
	int n = rand() % 100;
    // 생성한 난수를 반환
	return n;
}

// 최대 20자, 문자열의 저장 공간을 문자 배열로 선언함.
char outbuf[20];
// 문자열로 반환함 -> 모든 요소는 일단 문자열로 저장됨 -> 파라미터 e -> elem_t 구조체 -> 정수형임
char* str(elem_t e) {
    // 해당 요소(정수형)을 문자형으로 변환해줌.
	sprintf_s(outbuf, 20, "%d", e);
    // 문자형으로 변환된 요소를 반환함.
	return outbuf;
}
// 요소에 할당된 메모리를 해제함 -> 요소 자체를 제거할 때 불필요한 메모리 제거
void free_elem(elem_t e) {
    // int형은 기본형이므로 메모리 해지가 필요하지 않다.
    // 정수형 리스트가 아닌 문자형 리스트였다면 free를 통해 메모리 해제를 했을 것임 
}
// 두 요소를 비교함 -> 같으면 0 앞이 크면 양수, 뒤가 크면 음수
int compare(elem_t e1, elem_t e2) {
    // 두 요소의 차를 이용하면 앞의 사양에 맞게 함수를 만들 수 있다.
	return e1 - e2;
}

// arrlist_t, 리스트 구조체를 선언
typedef struct {
    // elem_t 리스트 -> 최대 100
	elem_t array[100];
    // int형의 사이즈 변수 있음 -> len에서 사용
	int size;
} arrlist_t;

// 리스트의 요소를 출력 한줄에 8개 씩
void print_list(arrlist_t* lp) {
	for (int i = 0; i < lp->size; ++i) {
		printf("%s ", str(lp->array[i]));
		if (i % 8 == 7)
			printf("\n");
	}
	printf("\n");
}
// 리스트의 맨 뒤에 요소를 더해줌
void add_list(arrlist_t* lp, elem_t val) {
	printf("값 %s를 리스트 맨 끝에 추가합니다.\n", str(val));
	lp->array[lp->size++] = val;
}
// 리스트의 중간에 요소를 삽입함
void insert_list(arrlist_t* lp, int pos, elem_t val) {
	printf("값 %s를 %d 번째에 삽입합니다.\n", str(val), pos);
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
	printf("%d 번째 값을 삭제합니다. 값 = %s\n", pos, str(result));
	lp->size--;
	return result;
}
// 특정 위치의 리스트의 요소를 수정함
elem_t update_list(arrlist_t* lp, int pos, elem_t val) {
	elem_t result = lp->array[pos];
	lp->array[pos] = val;
	printf("%d 번째 값을 %s로 변경합니다. 이전값 = %s\n", 
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

// lp가 가리키는 리스트에 e와 같은 값이 있으면 1, 없으면 0 
int contains(arrlist_t* lp, elem_t e) {
	// 리스트에서 요소가 있는지 탐색하는 함수를 써야함 -> find
	if (find(lp, e) == -1) return 0;
	return 1;
}

// lp가 가진 요소를 중복없이 새로운 리스트(newlp)에 추가해서 돌려준다
arrlist_t* remove_redundancy(arrlist_t* lp) {
	// 새로운 리스트 newlp 선언함 
	arrlist_t* newlp = (arrlist_t*)malloc(sizeof(arrlist_t));
	// 새로운 리스트의 크기를 0으로 초기화함
	init_list(newlp);
	// 리스트의 크기만큼 반복
	for (int i = 0; i < lp->size; i++){
		// 인덱스로 리스트의 요소를 꺼내야함 -> get
		int tmp = get(lp, i);
		// 해당 요소가 이미 새로운 리스트에 있는지 확인해야함 -> contains
		int det = contains(newlp, tmp);
		// 만약 요소가 들어 있지 않다면 새로운 리스트에 추가한다.
		if (det == 0){
			// 새로운 리스트에 추가한다. -> add_list
			add_list(newlp, tmp);
		} 
		// 만약 요소가 들어 있다면, pass한다. 
	}
	return newlp;
}

// 두 리스트의 교집합을 가지는 리스트를 만들어 반환한다
arrlist_t* compute_subset(arrlist_t* aptr, arrlist_t* bptr) {
	arrlist_t* newlp = (arrlist_t*)malloc(sizeof(arrlist_t));
	init_list(newlp);
	//aptr의 요소 값들을 각각 contains로 bptr에 있는지 확인한다. -> for, get ->contains
	for (int i = 0; i < aptr->size; i++){
		// 인덱스로 리스트의 요소를 꺼내야함 -> get
		int tmp = get(aptr, i);
		// tmp가 bptr에 있는지 확인한다. -> contains
		int det = contains(bptr, tmp);
		// 만약 판단 결과, 있다면, newlp에 저장한다. ->add_list
		if (det == 1) add_list(newlp, tmp);
		// 없으면 pass
	}
	newlp = remove_redundancy(newlp);
	return newlp;
}

// bptr가 가진 요소를 모두 aptr가 가리키는 리스트에 모두 추가한다.
void copy_list(arrlist_t* aptr, arrlist_t* bptr) {
	//bptr이 가진 요소를 파악해서 변수에 저장한다. -> for문으로 get함수를 쓴다.
	for (int i = 0; i < bptr->size; i++){
		// 인덱스로 리스트의 요소를 꺼내야함 -> get
		int tmp = get(bptr, i);
		// bptr이 가진 요소를 aptr에 추가한다. -> 맨 뒤에 넣는다. -> add_list를 사용한다.
		add_list(aptr, tmp);
	}
}

// 두 리스트의 합집합을 가지는 리스트를 만들어 반환한다
arrlist_t* compute_superset(arrlist_t* aptr, arrlist_t* bptr) {
	arrlist_t* newlp = (arrlist_t*)malloc(sizeof(arrlist_t));
	init_list(newlp);
	for (int i = 0; i < aptr->size; i++){
		// 인덱스로 리스트의 요소를 꺼내야함 -> get
		int tmp = get(aptr, i);
		// tmp가 bptr에 있는지 확인한다. -> contains
		int det = contains(bptr, tmp);
		// 만약 판단 결과, 없다면, newlp에 저장한다. ->add_list
		if (det == 0) add_list(newlp, tmp);
		// 있으면 pass
		// 지금까지 순수하게 리스트 a에만 있는 요소가 들어갔음 -> 리스트 b만 넣어주면 됨.
	}
	copy_list(newlp, bptr);
	newlp = remove_redundancy(newlp);
	return newlp;
}

void main() {
	// 리스트 a와 b를 선언함
	arrlist_t lista, listb;
	// 리스트 a를 초기화함 (size = 0)
	init_list(&lista);
	// 리스트 a에 20개의 요소를 입력받는다. 입력은 get_next를 통해 받는다. -> 난수 20개가 저장됨
	input_list(&lista, 20);
	// 리스트 b를 초기화함 (size = 0)
	init_list(&listb);
	// 리스트 b에 20개의 요소를 입력받는다. 입력은 get_next를 통해 받는다. -> 난수 20개가 저장됨
	input_list(&listb, 20);
	// 리스트 a에 저장된 난수들을 출력함
	printf("lista: \n"); print_list(&lista);
	// 리스트 b에 저장된 난수들을 출력함
	printf("listb: \n"); print_list(&listb);
	// 리스트a가 가진 요소를 중복없이 새로운 리스트에 추가해서 돌려준다 -> 리스트를 셋으로 변환함
	arrlist_t* aptr = remove_redundancy(&lista);
	// 리스트b가 가진 요소를 중복없이 새로운 리스트에 추가해서 돌려준다 -> 리스트를 셋으로 변환함
	arrlist_t* bptr = remove_redundancy(&listb);
	// 셋으로 변환한 (중복을 제거한) 리스트 a를 출력한다.
	printf("lista 중복제거: \n"); print_list(aptr);
	// 셋으로 변환한 (중복을 제거한) 리스트 b를 출력한다.
	printf("listb 중복제거: \n"); print_list(bptr);
	// 두 리스트 a,b의 교집합을 가지는 리스트를 만들어 반환한다
	arrlist_t* subset = compute_subset(&lista, &listb);
	// 두 리스트 a,b의 교집합을 출력한다.
	printf("교집합: \n"); print_list(subset);
	// 두 리스트 a,b의 합집합을 가지는 리스트를 만들어 반환한다
	arrlist_t* superset = compute_superset(&lista, &listb);
	// 두 리스트 a,b의 합집합을 출력한다.
	printf("합집합: \n"); print_list(superset);
}
