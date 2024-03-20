# boj_1405 : 미친로봇

# 각각의 경로를 모두 탐색하여 경로가 겹치치지 않는 확률을 구한다
# 경로가 겹치는 것이 탐색되는 경우 탐색을 중지하고 확률을 계산한다.


n, E, W, S, N = map(int, input().split())
board = [[0] * (2 * n + 1) for _ in range(2 * n + 1)]

def prob(x, y, cnt):
    if board[x][y] == 1: # 이미 방문한 경우 더이상 탐색할 필요가 없다.
        return 0
    if cnt == 0: # 마지막까지 성공적으로 탐색한 경우이다.
        return 1
    
    board[x][y] = 1
    ret = 0
    ret += E * prob(x, y + 1, cnt - 1)
    ret += W * prob(x, y - 1, cnt - 1)
    ret += S * prob(x + 1, y, cnt - 1)
    ret += N * prob(x - 1, y, cnt - 1)
    board[x][y] = 0
    return ret

print(prob(n, n, n) / (100 ** n))

# 부동 소수점 연산을 최소화 해서 연산시간을 최소화하고, 정확도를 높인다.
