#include <stdio.h>

// 두 개의 정수를 비교하는 함수(작은 값을 반환)
int compare(int a, int b)
{
    if (a <= b)
        return a;
    else
        return b;
}

// 배열 A의 모든 요소를 비교해서 배열의 최솟값의 인덱스를 반환
int minimum_index(int A[], int len)
{
    int answer = 0;
    // 배열에 원소가 한 개일 경우, 비교할 게 없으므로 A[0]의 인덱스인 0을 반환한다.
    if (len == 1)
        answer = 0;
    // 배열에 원소가 여러 개일 경우, 재귀 호출을 이용하여 각각 비교하여 최솟값의 인덱스를 반환한다.
    else if (compare(A[len - 1], A[minimum_index(A, len - 1)]) == A[len - 1])
        answer = len - 1;
    else
        answer = minimum_index(A, len - 1);
    return answer;
}

void selection_sort(int A[], int len)
{
    // 배열에 원소가 한 개일 경우, 정렬할 게 없으므로 그냥 끝낸다.
    if (len == 1)
        // 함수가 void 형이므로 반환형이 없으므로 빈 return값을 반환한다.
        return;

    // 배열에 원소가 여러 개일 경우
    // 배열의 모든 요소를 비교하여 배열의 최솟값을 반환한다.
    int min = minimum_index(A, len);
    
    // 배열의 맨 앞에 배열의 최솟값을 넣어야 하므로 배열의 맨 앞에 값을 tmp에 저장한다.
    int tmp = A[0];
    // 배열의 맨 앞에 배열의 최솟값을 넣는다.
    A[0] = A[min];
    // 원래 최솟값이 있던 위치에 백업해둔 맨 앞의 값을 넣는다.
    A[min] = tmp;
    // 배열의 맨 앞은 정렬이 된 상태이므로 제외하고, 그 다음부터 끝까지 다시 함수를 돌린다.
    selection_sort(A + 1, len - 1);
}

int main()
{
    int B[] = {12, 23, 53, 44, 55, 63, 57, 18, 9, 10};
    // 배열의 크기가 고정되어있지 않으므로 원소의 개수를 계산해준다.
    int n = sizeof(B) / sizeof(B[0]);
    // 정렬하기 전 배열 출력
    for (int i = 0; i < n; i++)
        printf("%d ", B[i]);
    printf("\n");
    // 정렬
    selection_sort(B, n);
    // 정렬한 후 배열 출력
    for (int i = 0; i < n; i++)
        printf("%d ", B[i]);
    return 0;
}