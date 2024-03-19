# boj_28325 : 호숫가의 개미굴

"""
주의 : N의 크기만큼 재귀호출이 필요하다.
setrecursionlimit을 N의 크기보다 크게 하여 런타임 에러를 방지해야 한다.
"""
# ==================================================
# DP를 이용한 풀이
import sys
sys.setrecursionlimit(300000)
input = sys.stdin.readline

N = int(input())
sub_rooms = list(map(int, input().split()))


def room(n, live): # n = n-1 -> 0
    # 1. 기저 사례
    if n == 0:
        return 1 if live else sub_rooms[0]
    if n == 1:
        if live: return room(0, 0) + 1
        if room_n_flag: return room(0, 0) + sub_rooms[1]
        return max(room(0, 1), room(0, 0)) + sub_rooms[1]
    
    # 2. 캐시 확인
    if cache[n][live] != -1: return cache[n][live]
    
    # 3. 계산
    if live:
        cache[n][live] = room(n-1, 0) + 1
    else:
        cache[n][live] = max(room(n-1, 1), room(n-1, 0)) + sub_rooms[n]
    return cache[n][live]

ret = 0
cache = [[-1] * 2 for _ in range(N)]
room_n_flag = 0
ret = max(ret, room(N-1, 0))

cache = [[-1] * 2 for _ in range(N)]
room_n_flag = 1
ret = max(ret, room(N-1, 1))
print(ret)

# ==================================================
# 그리디 알고리즘을 이용한 풀이

# 개미굴에 쪽방이 있는 경우 무조건 쪽방을 이용하는 것이 유리하다.