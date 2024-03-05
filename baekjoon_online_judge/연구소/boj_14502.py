# boj_14502.py : 연구소

import sys
from collections import deque
input = sys.stdin.readline

delta_pos = {'N':(-1, 0), 'S':(1, 0), 'W':(0, -1), 'E':(0, 1)} # (x, y)

def buildWall(): # TODO 조합으로 구현을 바꿀 수 있을 것
    new_wall = []
    for w1 in range(N * M):
        if lab_origin[w1 // M][w1 % M]: continue

        for w2 in range(w1 + 1, N * M):
            if lab_origin[w2 // M][w2 % M]: continue

            for w3 in range(w2 + 1, N * M):
                if lab_origin[w3 // M][w3 % M]: continue

                new_wall.append((w1, w2, w3))
    return new_wall

def findVirusOrigin(lab, queue):
    for i in range(N * M):
        x = i // M
        y = i % M
        if lab[x][y] == 2: # 바이러스
            queue.append((x, y))

def spreadVirus(lab, queue):
    while queue:
        x, y = queue.popleft()
        for dir in ['N', 'S', 'W', 'E']:
            nx, ny = x + delta_pos[dir][0], y + delta_pos[dir][1]
            if outOfRange(nx, ny): continue
            if lab[nx][ny] == 0:
                lab[nx][ny] = 2
                queue.append((nx, ny))

def calcSafeArea(lab):
    cnt = 0
    for i in range(N * M):
        if lab[i // M][i % M] == 0:
            cnt += 1
    return cnt

def outOfRange(x, y):
    return x < 0 or x >= N or y < 0 or y >= M

N, M = map(int, input().split())
lab_origin = [list(map(int, input().split())) for _ in range(N)]

max_safe_area = 0

new_walls = buildWall()
for w1, w2, w3 in new_walls:
    virus_queue = deque()
    spread_lab = [l[:] for l in lab_origin]

    # 1. 벽 세우기
    spread_lab[w1 // M][w1 % M] = 1
    spread_lab[w2 // M][w2 % M] = 1
    spread_lab[w3 // M][w3 % M] = 1
    
    # 2. 바이러스 퍼뜨리기
    findVirusOrigin(spread_lab, virus_queue)
    spreadVirus(spread_lab, virus_queue)
    
    # 3. 안전영역 계산
    max_safe_area = max(calcSafeArea(spread_lab), max_safe_area)

print(max_safe_area)
            
"""
해결과정

1. 빈칸의 3개의 벽을 세운다
    - 3중 for문으로 모든 경우의 수를 찾는다
    - depth 3의 재귀함수로 구현한다.
2. 바이러스를 퍼뜨린다
    - 새로 찾는 영역을 큐에 넣어 BFS로 구현한다.
    - 영역을 새로 찾을때마다 재귀 호출하여 DFS로 구현한다.
3. 안전영역을 계산한다


각 단계를 함수로 구현했다.
함수 내부에서 다른 함수를 연속적으로 호출하는 식이 아니라
main 부분에서 각 단계의 함수를 차례로 호출하도록 해서 직관성을 높였다.

TODO 
- 벽을 세우는 부분을 조합으로 구현할 수 있을 것 같다.
- 벽을 세우는 부분 for 문에서 다른 함수를 호출하는 식으로 동작한다면 new_walls 리스트를 생성하지 않아도 되어 메모리 절약 효과가 있을 것
- 바이러스를 퍼뜨리는 부분을 DFS로도 구현이 가능하다
- lab을 deepcopy 하지 않고 구현이 가능하다면 시간 개선효과가 클 것

"""