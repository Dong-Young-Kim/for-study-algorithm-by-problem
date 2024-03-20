# boj_25401 : 카드 바꾸기

import sys
input = sys.stdin.readline

N = int(input())
card = list(map(int, input().split()))

# 바꾸지 않을 카드의 개수를 센 후, 그 최대값을 구한다.
f = 2
for i in range(0, N):
    for j in range(i + 1, N):

        if (card[j] - card[i]) % (j - i) == 0:
            d = (card[j] - card[i]) // (j - i)
            cnt = 0
            for k in range(0, N):
                if card[i] + (k - i) * d == card[k]:
                    cnt += 1
            f = max(f, cnt)

print(N - f)

"""
어떠한 경우에도 2장의 카드는 바꾸지 않아도 된다.
즉 2장의 카드를 고정하고 나머지 N-2개의 카드 중 바꾸어야 하는 개수를 세면 문제 해결이 가능

O(N^3)의 시간복잡도로 N의 최대값이 500이므로 충분히 해결 가능하다.
"""
