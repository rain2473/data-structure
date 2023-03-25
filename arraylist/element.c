// 리스트 안의 각각의 요소를 구현하는 코드
// element.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "element.h"

// 다음 요소를 생성함
element new_element()
{
    // 0 ~ 100까지 난수 생성
    int n = rand() % 100;
    // 생성한 난수를 반환
    return n;
}
// 최대 20자, 문자열의 저장 공간을 문자 배열로 선언함.
char outbuf[20];
// 문자열로 반환함 -> 모든 요소는 일단 문자열로 저장됨 -> 파라미터 e -> element 구조체 -> 정수형임
char *to_str(element e)
{
    // 해당 요소(정수형)을 문자형으로 변환해줌.
    sprintf_s(outbuf, 20, "%d", e);
    // 문자형으로 변환된 요소를 반환함.
    return outbuf;
}
// 요소에 할당된 메모리를 해제함 -> 요소 자체를 제거할 때 불필요한 메모리 제거
void free_element(element e)
{
    // int형은 기본형이므로 메모리 해지가 필요하지 않다.
    // 정수형 리스트가 아닌 문자형 리스트였다면 free를 통해 메모리 해제를 했을 것임
}
// 두 요소를 비교함 -> 같으면 0 앞이 크면 양수, 뒤가 크면 음수
int compare(element e1, element e2)
{
    // 두 요소의 차를 이용하면 앞의 사양에 맞게 함수를 만들 수 있다.
    return (e1 - e2);
}