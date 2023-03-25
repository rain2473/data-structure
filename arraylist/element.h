// 리스트 안의 각각의 요소를 정의하는 코드
// element.h
#pragma once
// element, 리스트의 요소 구조체 -> 정수형, 숫자만 저장하는 정수 리스트임.
typedef int element;
// 다음 요소를 생성함 -> 리스트에 넣을 다음 요소를 랜덤하게 생성함 (입력 받을 순 없짜나)
element new_element();
// 문자열로 반환함 -> 모든 요소는 일단 문자열로 저장됨
char *to_str(element e);
// 요소에 할당된 메모리를 해제함 -> 요소 자체를 제거할 때 불필요한 메모리 제거
void free_element(element e);
// 두 요소를 비교함 -> 같으면 0 앞이 크면 양수, 뒤가 크면 음수
int compare(element e1, element e2);