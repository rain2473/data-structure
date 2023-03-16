// 리스트 안의 각각의 요소를 정의하는 코드
// elem.h
#pragma once
// elem_t, 리스트의 요소 구조체 -> 정수형, 숫자만 저장하는 정수 리스트임.
typedef int elem_t;
// 다음 요소를 생성함 -> 리스트에 넣을 다음 요소를 랜덤하게 생성함 (입력 받을 순 없짜나)
elem_t get_next();
// 문자열로 반환함 -> 모든 요소는 일단 문자열로 저장됨
char* str(elem_t e);
// 요소에 할당된 메모리를 해제함 -> 요소 자체를 제거할 때 불필요한 메모리 제거
void free_elem(elem_t e);
// 두 요소를 비교함 -> 같으면 0 앞이 크면 양수, 뒤가 크면 음수
int compare(elem_t e1, elem_t e2);
