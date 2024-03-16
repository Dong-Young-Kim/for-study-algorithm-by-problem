# boj_15961 : 회전초밥
import sys
N, d, k, c = map(int, sys.stdin.readline().split())
belt = [int(sys.stdin.readline()) for _ in range(N)]

# count 함수는 시간 소모가 크다
# def typeOfMenu(type_cnt):
#     type_cnt[belt[i % N]] += 1
#     type_cnt[belt[(i - k) % N]] -= 1
#     if type_cnt[c] == 0: return d - type_cnt.count(0) + 2
#     else: return d - type_cnt.count(0) + 1


type_cnt = [0] * (d + 1) # [0]은 전체 종류

for i in range(k):
    if type_cnt[belt[i]] == 0: type_cnt[0] += 1
    type_cnt[belt[i]] += 1

# max_type = type_cnt[0] + 1 if type_cnt[c] == 0 else type_cnt[0]
max_type = 0
for i in range(0, N):
    if type_cnt[belt[i]] == 1: type_cnt[0] -= 1
    type_cnt[belt[i]] -= 1

    if type_cnt[belt[(i + k) % N]] == 0: type_cnt[0] += 1
    type_cnt[belt[(i + k) % N]] += 1

    max_type = max(max_type, type_cnt[0] + 1 if type_cnt[c] == 0 else type_cnt[0])
    
print(max_type)

# type_cnt[0]: 전체 종류
# type_cnt[i]: ]: i번 초밥의 개수 
# type_cnt[belt[i]]: 벨트 위 i번째 초밥의 개수

"""
구간을 잘 생각하자
N = 8, k = 4라면 계산횟수는 5가 아니라 8이다
앞 위가 연결되어 있기 때문

인덱스에서 % n 을 해서 한바퀴를 도는 경우를 고려해야합니다.
n-1 인덱스를 시작점으로 k 개 범위가 잡힌 경우도 고려해야합니다.
8 30 4 30
9
25
7
9
7
30
2
7
=> 5
"""