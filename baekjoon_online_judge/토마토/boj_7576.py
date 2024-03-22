# boj_7576 : 토마토

import sys
from collections import deque
input = sys.stdin.readline

delta_pos = [(-1, 0), (1, 0), (0, -1), (0, 1)]
M, N = map(int, input().split())
box = [list(map(int, input().split())) for _ in range(N)]
# 0: 안익은 토마토, 1: 처음부터 익어있던 토마토, 정수 n: n일차에 익어있는 토마토 익는데 n-1 걸림

q = deque()
for i in range(N*M):
    if box[i // M][i % M] == 1: q.append((i // M, i % M))

# bfs
while(q):
    x, y = q.popleft()
    day = box[x][y]
    for d in delta_pos:
        nx, ny = x + d[0], y + d[1]
        if nx < 0 or nx >= N or ny < 0 or ny >= M : continue # out of range
        if not box[nx][ny]:
            box[nx][ny] = day + 1
            q.append((nx, ny))

# find not Ripped
for i in range(N * M):
    x, y = i // M, i % M
    if not box[x][y]:
        day = 0
        break
print(day - 1)
