from collections import deque
T = int(input())
for _ in range(T):
    n, m = map(int, input().split())
    prios = deque(map(int, input().split()))
    Q = deque([(i, p) for i, p in enumerate(prios)]) # (index, priority)
    cnt = 0
    while Q:
        if Q[0][1] == max(Q, key=lambda x: x[1])[1]:
            cnt += 1
            if Q[0][0] == m:
                print(cnt)
                break
            else:
                Q.popleft()
        else:
            Q.append(Q.popleft()) # move to the end of the queue

# 람다식을 결합한 max 함수의 사용법
# max(iterable, *iterables, key, default)
            