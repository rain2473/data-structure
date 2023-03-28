# 팬케이크 정렬 파이썬 코드 - 변수는 리스트
def  pancake (a):
    #  탈출조건, 리스트의 길이가 1이면 탈출
    if len(a) == 1:
        return a
    else:
        # 리스트의 최댓값의 인덱스를 변수로 저장
        max_idx = a.index(max(a))
        #  최댓값 전까지 역순으로 뒤집음
        tmp = a[:max_idx + 1][::-1] + a[max_idx + 1:]
        # 전체를 뒤집음
        tmp = tmp[::-1]
        #  최댓값이 맨 뒤로 갔으므로, 맨 뒤의 최댓값은 더이상 고려하지  않는다.
        completed = tmp[-1]
        #  재귀호출로 해결
        answer = pancake(tmp[:-1]) + [completed]
        # 반환값은 정렬된 리스트
        return answer

# TestCase
a = [2,10,46,58,32,16,5,11]

print(pancake(a))
