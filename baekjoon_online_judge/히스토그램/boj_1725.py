# boj_1725 : 히스토그램

# 제시된 히스토그램 내부에 가장 넓이가 큰 직사각형을 찾는 문제이다.
# O(n^2) 의 완전탐색으로는 제한 시간 안에 문제를 풀 수 없으므로 분할 정복을 통해서 문제를 해결한다.


# 1. 분할 정복과 그리디 알고리즘을 결합한 해법 ===============================
import sys
def solve(start, end): # [start. end)
    # 1. 기저사례
    if end - start == 1: return hist[start]

    # 2. 분할
    mid = int((start + end) / 2)
    max_area = max(solve(start, mid), solve(mid, end))

    # 3. 걸친 경우
    s = mid - 1
    e = mid + 1
    h = min(hist[s], hist[s+1])
    max_area = max(max_area, (e - s) * h)
    while s > start or e < end:
        # TODO: 조건문 압축이 가능할 것
        if s == start: 
            e += 1
            h = min(h, hist[e-1])
        elif e == end: 
            s -= 1
            h = min(h, hist[s])
        else:
            if hist[s-1] < hist[e]: 
                e += 1
                h = min(h, hist[e-1])
            else: 
                s -= 1 
                h = min(h, hist[s])
        max_area = max(max_area, (e - s) * h)
    
    return max_area

# input을 sys.stdin.readline()으로 바꾸어서 시간 초과를 해결
n = int(sys.stdin.readline())
hist = [int(sys.stdin.readline()) for _ in range(n)]
print(solve(0, n))

# ==========================================================

# 양쪽에 걸쳤을 때 큰 쪽으로만 확장하는 그리디를 적용해도 되는 이유
# 전제) 1. 확장 시에 높이는 증가할 수 없다. 2. 넓이는 무조건 1씩 증가한다
# 최대한으로 양쪽으로 이동하는 행위는 결국
# 모든 직사각형의 높이를 내림차순으로 배열한 후, 초기 높이에서 작아지는 방향으로 직사각형의 높이를 변화시키는 것으로 계산하는 방법과 동일하다

"""
TC

3
1
1
1
=> 3

7
7
1
5
9
6
7
3
=> 20

7
2
1
4
5
1
3
3
=> 8

7
0
5
7
5
5
3
1
=> 20

4
1
4
3
3
=> 9

"""
