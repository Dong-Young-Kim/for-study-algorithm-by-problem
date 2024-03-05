# boj_1260 : DFS와 BFS

# 그래프 탐색 이론의 기본 문제

import sys
from collections import deque

input = sys.stdin.readline
N, M, V = map(int, input().split()) # 정점 수, 간선 수, 시작 정점

# 1. adjacency List
# adjacency = [[]] * N
# for _ in range(M):
#     v1, v2 = map(int, input().split())
#     adjacency[v1].append(v2)
#     adjacency[v2].append(v1)

# 2. adjacency Matrix
adjacency = [[0] * (N+1) for _ in range(N+1)]
for _ in range(M):
    v1, v2 = map(int, input().split())
    adjacency[v1][v2] = 1
    adjacency[v2][v1] = 1

visited = [0] * (N+1)
def dfs_recur(v):
    print(v, end=' ')
    visited[v] = 1
    for i in range(N):
        if adjacency[v][i] and not visited[i]:
            dfs_recur(i)

def dfs(s): # v: 시작 정점
    visited = [0] * (N+1) # 방문 여부 초기화
    stack = deque([s]) # Seed 삽입
    while stack:
        v = stack.pop() # pop
        if visited[v]: continue
        visit(v)
        visited[v] = 1
        for i in range(N, 0, -1): # idx 가 최소인 노트부터 방문하도록 역순으로 탐색
        # for i in range(1, (N+1)):
            if adjacency[v][i] and not visited[i]:
                stack.append(i) # push

def bfs(s): # v: 시작 정점
    visited = [0] * (N+1) # 방문 여부 초기화
    queue = deque([s]) # Seed 삽입
    visited[s] = 1
    while queue:
        v = queue.popleft() # dequeue
        visit(v)
        for i in range(1, (N+1)):
            if adjacency[v][i] and not visited[i]:
                queue.append(i) # enqueue
                visited[i] = 1 # bfs 에서 visited[]는 방문 여부 의미보다는 '탐색' 여부의 의미와 가깝다

def visit(v): # v: 방문 중인 정점
    global out_buf
    out_buf += str(v) + ' '

out_buf = ''
if out_buf: out_buf.pop() # 마지막 공백 제거
dfs(V)
print(out_buf)

out_buf = ''
if out_buf: out_buf.pop() # 마지막 공백 제거
bfs(V)
print(out_buf)
