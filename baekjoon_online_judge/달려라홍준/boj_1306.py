# boj_1306 : 달려라 홍준

# 입력된 길이 N의 배열에서 길이가 K인 구간의 최대값을 구하는 문제
# 길이가 고정되어 있고, 1칸씩 이동하므로 슬라이딩 윈도우 기법을 사용하여 풀 수 있다.

# 총 길이는 N, 윈도우의 크기는 2M - 1

import sys
from collections import deque

N, M = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))
window = deque(arr[:2 * M - 1]) 
crnt_max = max(window)
window_maxes = [str(crnt_max)]

# sliding window
for i in range(2 * M - 1, N):
    window.append(arr[i])

    if arr[i] > crnt_max: 
        crnt_max = arr[i]
    
    poped = window.popleft()
    if poped == crnt_max:
        crnt_max = max(window) if poped != arr[i] else arr[i] # to save time

    window_maxes.append(str(crnt_max))

print(' '.join(window_maxes))

# 동일한 값이 입출력 될 때 계산 하지 않도록 코드를 개선해볼 것 (fin)
# 세그먼트 트리를 통해서 max 값 연산 개선이 가능
# 문자열 연산은 시간이 많이 걸리므로, 리스트 연산을 사용하여 최대값을 저장하고 마지막에 join하여 출력하는 방법을 사용


"""
슬라이딩 윈도우
윈도우 내 구간에서 최대값을 구하는 문제

구간의 max/min 값을 기억하고 있다가
1. 새로운 max/min 값이 구간에 들어오면 값을 갱신
2. max/min 값과 동일한 값이 탈출하면 윈도우의 max/min 값을 계산 O(N)
2-1. 만약 이 방법을 사용했는데도 시간이 부족하다면 세그먼트 트리를 통해 O(logN) 시간에 min/max를 계산할 것


세그먼트 트리
세그먼트 트리를 이용한다면 구간의 최대/최소값을 O(longN)에 계산할 수 있으나
이 문제에서는
1. 배열 값의 갱신이 없고,
2. 크기가 변하지 않는 구간이 1씩 이동하는 
성질이 있으므로 세그먼트 트리를 사용하기에는 조금 아쉽다
"""

"""
TC
8 3
1 3 1 3 5 3 6 7
-> 5 5 6 7

10 2
10 9 8 7 6 5 4 3 2 1
-> 10 9 8 7 6 5 4 3
"""