# bj_25404 : 주차타워 

# 다이나믹 프로그래밍을 통한 풀이
import sys
from functools import lru_cache
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))

# 좌표압축, 번호가 c인 차들의 인덱스 목록을 cidx[c]에 저장
sorted_arr = sorted(list(set(arr)))
compressed_arr = {sorted_arr[i]: i for i in range(len(sorted_arr))}
cidx = [[] for _ in range(len(sorted_arr))]
for i in range(N):
    cidx[compressed_arr[arr[i]]].append(i)
    # 자연스럽게 cidx는 인덱스 순서대로 저장된다.

## LEGACY
# # 번호가 c인차를 모두 빼고, e가 가장 아래에 위치하도록 하는 최소 이동 횟수 O(N)
# @lru_cache(maxsize=None)
# def dp(c, e):
#     if c == 0:
#         return min(circleDist(0, i) + calcPath(c, i, e) for i in cidx[c])
#     return min(dp(c - 1, i) + calcPath(c, i, e) for i in cidx[c])


# 번호가 c인차를 모두 빼고, e가 가장 아래에 위치하도록 하는 최소 이동 횟수 O(N)
@lru_cache(maxsize=100005)
def dp(c, e):
    min_val = sys.maxsize
    for i in range(len(cidx[c])):
        c1, c2 = cidx[c][i], cidx[c][i - 1]
        path = c2 - c1 if c1 <= c2 else N - (c1 - c2)
        if c == 0:
            min_val = min(min_val, circleDist(0, c1) + path + circleDist(c2, e)) # 순방향
            min_val = min(min_val, circleDist(0, c2) + path + circleDist(c1, e)) # 역방향
        else: 
            min_val = min(min_val, dp(c - 1, c1) + path + circleDist(c2, e)) # 순방향
            min_val = min(min_val, dp(c - 1, c2) + path + circleDist(c1, e)) # 역방향
    return min_val

def circleDist(a, b):
    return min(abs(a - b), N - abs(a - b))

if len(compressed_arr) == 1: print(N - 1)
else: print(min(dp(len(cidx) - 1, i) for i in cidx[-1]))

"""
dp 함수는 N 번 호출되고, 한번의 함수에서 K번의 연산이 일어난다.
(K는 각 번호를 가진 차량의 개수)

동일한 번호를 갖는 차량이 많아질수록 시간 복잡도가 상승하며 이 풀이의 시간 복잡도는 O(K^2 * N))이 된다.
"""