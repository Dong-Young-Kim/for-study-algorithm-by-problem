# boj_28324 : 스케이트 연습

# 풀이 순서를 뒤집으면 그리디 알고리즘으로 해결이 가능하다

import sys
input = sys.stdin.readline
N = int(input())
limit = list(map(int, input().split()))
vel, score = 0, 0 # 끝나는 지점의 속도 = 0
for i in range(N - 1, -1, -1):
    vel = min(limit[i], vel + 1)
    score += vel
print(score)
