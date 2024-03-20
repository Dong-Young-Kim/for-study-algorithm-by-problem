# boj_28325 : 호숫가의 개미굴

# ==================================================
# 그리디 알고리즘을 이용한 풀이
# 개미굴에 쪽방이 있는 경우 무조건 쪽방을 이용하는 것이 유리하다.

import sys
input = sys.stdin.readline

N = int(input())
sub_room = list(map(int,input().split()))

live = sum(sub_room)
# 모든 방에 쪽방이 없으면 처음과 끝이 연결된 것을 고려하여 예외를 둔다. 
if live == 0: 
    live = N // 2

else: 
    # 쪽방이 있는 방의 인덱스를 찾는다.
    for idx in range(N): 
        if sub_room[idx]: 
            s = idx
            break
    sub_x = 0
    for i in range(s + 1, N + s + 1): # 마지막 결과를 더해주기 위해서 +1이 필요하다
        if not sub_room[i % N]:
            sub_x += 1
        else:
            live += (sub_x + 1) // 2
            sub_x = 0

print(live)

"""
쪽방이 있는 경우 어떠한 경우에도 쪽방을 이용하는 것이 유리하다.

n개의 빈 방이 존재하는 경우
1. 앞 뒤가 연결된 경우 N // 2개의 개미가 살 수 있고, 
2. 앞 뒤가 연결되지 않은 경우 각 구간마다 (k + 1) // 2개의 개미가 살 수 있다.

쪽방이 하나도 없는 경우만 예외로 둔 후 2.를 해결하여 문제를 해결할 수 있다.

"""