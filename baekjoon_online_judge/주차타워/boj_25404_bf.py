# bj_25404 : 주차타워

# 브루트포스 알고리즘을 통한 풀이

import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))
visited = [False] * N
min_total_move = sys.maxsize

def solve(cur, remain, move):
    if remain == 0:
        global min_total_move
        min_total_move = min(min_total_move, move)
        return

    for new in range(N):
        if visited[new] or arr[cur] > arr[new]: continue
        visited[new] = True
        solve(new, remain - 1, move + min(abs(cur - new), N - abs(cur - new)))
        visited[new] = False

for i in range(N):
    visited[i] = True
    solve(i, N - 1, min(i, N - i))
    visited[i] = False

print(min_total_move)

"""
브루트포스 알고리즘으로 풀기

어떠한 차 부터 빼는 것이 가장 이동 횟수가 적은지를 찾는 문제이다.
즉 모든 차를 어떤 순서로 빼야하는지 결정하는 순열 문제와 같다
시간 복잡도는 O(N!) 이므로 N이 10 이하일 때만 사용 가능하다
"""
