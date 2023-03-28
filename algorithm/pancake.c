#include <stdio.h>
#include <stdio.h>

// 두 개의 정수를 비교하는 함수(작은 값을 반환)
int compare(int a, int b)
{
    if (a <= b)
        return a;
    else
        return b;
}

// 배열 A의 모든 요소를 비교해서 배열의 최댓값의 인덱스를 반환
int maximum_index(int A[], int len)
{
    int answer = 0;
    // 배열에 원소가 한 개일 경우, 비교할 게 없으므로 A[0]의 인덱스인 0을 반환한다.
    if (len == 1)
        answer = 0;
    // 배열에 원소가 여러 개일 경우, 재귀 호출을 이용하여 각각 비교하여 최댓값의 인덱스를 반환한다.
    else if (compare(A[len - 1], A[maximum_index(A, len - 1)]) != A[len - 1])
        answer = len - 1;
    else
        answer = maximum_index(A, len - 1);
    return answer;
}

// 배열 A을 현재 순서의 역순으로 뒤집음
void reverse(int A[], int len)
{
    // 입력과 크기가 같은 정답 배열 선언
    int *answer[len];
    // 배열에 원소가 한 개거나 0일 경우, 뒤집을 수 없으므로, 그대로를 반환
    if (len < 2)
        return;
    // 배열에 원소가 2개 이상일 경우, 양끝의 원소를 맞바꾸고, 재귀호출
    else
    {
        // 맨 앞의 원소를 백업
        int tmp = A[0];
        // 맨 앞에 맨 뒤 원소 입력
        A[0] = A[len - 1];
        // 맨 뒤에 백업해둔 맨 앞 원소 입력
        A[len - 1] = tmp;
        // 재귀호출
        reverse(A + 1, len - 2);
    }
}

// 원하는 부분만 잘라내는 함수
// 원하는 결과물을 미리 선언해두어야한다.
// new_len는 잘라내고자하는 길이이다.
void slicing(int A[], int answer[], int new_len)
{
    // 잘라내고자 하는 길이가 0인 경우 잘라낼 것이 없으므로 종료
    if (new_len == 0)
        return;
    // 그 외 경우엔 복사후 재귀호출
    else
    {
        // 잘라내고자하는 자리부터 뒤에서 앞으로 복사
        answer[new_len - 1] = A[new_len - 1];
        // 재귀호출
        slicing(A, answer, new_len - 1);
    }
}

// 팬케이크 문제를 푸는 알고리즘
void palencake(int A[], int len)
{
    // 길이가 1인 경우, 정렬이 필요 없으므로 종료
    if (len == 1)
        return;
    // 최대값의 인덱스 값을 구함
    int max_idx = maximum_index(A, len);
    // 맨 위에서 최대값까지의 길이와 같은 슬라이싱을 수행할 임시 배열 선언
    int *tmp[max_idx + 1];
    // 맨 위에서 최대값까지 슬라이싱해서 tmp에 저장
    slicing(A, tmp, max_idx + 1);
    // tmp를 뒤집기함
    reverse(tmp, max_idx + 1);
    // 뒤집어진 tmp 값을 A에 대입하여 적용함.
    // 슬라이싱이라는 함수의 원래 기능, 목적에는 부합하지 않으나
    // 코드의 부작용을 역으로 활용하면 원하는 부분까지만 바꾸는것도 가능하다.
    // 0 ~ 최댓값위치까지만 역순으로 뒤집어지고 이후로는 원래를 유지함.
    slicing(tmp, A, max_idx + 1);
    // A의 전체를 뒤집음
    reverse(A, len);
    // 재귀호출, 맨 밑을 제외하고 다시 팬케이크를 수행함.
    palencake(A, len - 1);
}

void main()
{
    // 테스트용 배열 임의로 선언
    int a[] = {2, 10, 46, 58, 32, 16, 5, 11};
    // 배열의 길이 구하기
    int len = sizeof(a) / sizeof(int);
    // 팬케이크 함수 실행
    palencake(a, len);
    // 결과를 출력
    for (int i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}