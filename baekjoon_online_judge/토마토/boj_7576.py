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

while(q):
    x, y = q.popleft()
    for d in delta_pos:
        nx, ny = x + d[0], y + d[1]
        if nx < 0 or nx >= N or ny < 0 or ny >= M : continue # out of range
        # 여러개의 익은 토마토가 있을 수 있으므로
        # 익는데 더 적은 일수가 걸리는 토마토가 있다면 새로 더 적은 일수로 업데이트 한다.
        if box[nx][ny] == 0 or box[nx][ny] > box[x][y] + 1:
            box[nx][ny] = box[x][y] + 1
            q.append((nx, ny))

maxR = 1
for i in range(N*M):
    x, y = i // M, i % M
    if box[x][y] == 0:
        maxR = 0
        break
    if box[x][y] > maxR:
        maxR = box[x][y]
print(maxR - 1)
