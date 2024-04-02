# bj_25404 : 주차타워 

# 다이나믹 프로그래밍 + 슬라이딩 윈도우를 통한 풀이
import sys
from bisect import bisect_left
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))

# 좌표압축, 번호가 c인 차들의 인덱스 목록을 cidx[c]에 저장
sorted_arr = sorted(list(set(arr)))
compressed_arr = {sorted_arr[i]: i for i in range(len(sorted_arr))}
cidx = [[] for _ in range(len(sorted_arr))]
for i in range(N):
    cidx[compressed_arr[arr[i]]].append(i) # cidx[] is aligned automatically

cache = [[-1 for _ in range(len(cidx[i + 1]))] for i in range(len(cidx) - 1)]

def circleDist(a, b):
    return min(abs(a - b), N - abs(a - b))

for c in range(len(cidx)):

    # 1. 출발지점에서 도착지점으로 이동하는 경로의 길이 계산 (o2p = until endpoint cost)
    o2p = [sys.maxsize] * len(cidx[c])
    for i in range(len(cidx[c])):
        # start point = c1, endpoint = c2 (if 순방향, 역방향인경우 반대)
        c1, c2 = cidx[c][i], cidx[c][i - 1]
        # sp = start point to end point cost (sp1 : end point = c1)
        sp1 = sp2 = c2 - c1 if c1 <= c2 else N - (c1 - c2)

        # add until start point cost
        if c == 0:
            sp1 += circleDist(0, c1) # path = c1 -> c2
            sp2 += circleDist(0, c2) # path = c2 -> c1
        else:
            sp1 += cache[c - 1][i] # path = c1 -> c2
            sp2 += cache[c - 1][i - 1] # path = c2 -> c1
        
        o2p[i - 1] = min(o2p[i - 1], sp1) # endpoint = c2
        o2p[i] = min(o2p[i], sp2) # endpoint = c1

    # o2p 최적화 (o2p의 minidx를 기준으로 순방향으로 cost를 최적화)
    mi = o2p.index(min(o2p)) # minidx
    for dir in range(2): # 0: 순방향, 1: 역방향
        ci = bi = mi
        for i in range(1, len(o2p)):
            bi = ci
            ci = (mi + i) % len(o2p) if not dir else (mi - i) % len(o2p)
            o2p[ci] = min(o2p[ci], o2p[bi] + circleDist(cidx[c][ci], cidx[c][bi]))

    # 2. 도착지점에서 E로 이동하는 경로의 길이
    if c == len(cidx) - 1: 
        cache.append(o2p)
        break
    for e in range(len(cidx[c + 1])):
        # calc index side of cidx[c + 1][e]
        mididx = bisect_left(cidx[c], cidx[c + 1][e])
        befidx, aftidx = mididx - 1, mididx % len(o2p)

        # cidx and o2p has same index
        cache[c][e] = min(o2p[befidx] + circleDist(cidx[c][befidx], cidx[c + 1][e]), 
                          o2p[aftidx] + circleDist(cidx[c][aftidx], cidx[c + 1][e]))
        
        # # calc all index of o2p
        # cache[c][e] = min(o2p[x] + circleDist(cidx[c][x], cidx[c + 1][e]) for x in range(len(o2p)))

if len(compressed_arr) == 1: print(N - 1) # all cars number is same
else: print(min(cache[-1]))

"""
TC

90
4 3 5 2 2 3 2 3 1 1 3 7 4 1 1 1 4 3 6 4 1 2 2 1 5 2 1 1 7 4 4 4 1 3 1 3 5 2 3 1 1 2 2 4 1 2 4 4 5 1 1 1 4 5 1 2 2 1 1 2 1 2 4 6 3 1 1 4 3 1 6 1 7 5 3 5 2 2 5 2 1 1 2 1 1 3 1 4 2 4

cache[answer]
[87, 86, 84, 95, 96, 99, 111, 115, 116, 117, 107, 106, 103, 101, 96, 95, 93, 90, 88]
[175, 171, 171, 170, 163, 171, 173, 176, 174, 178, 178, 175]
[256, 248, 246, 247, 241, 240, 239, 243, 246, 247, 252, 242, 243, 259, 257]
[318, 326, 324, 322, 323, 327, 325, 322]
[392, 403, 396]
[455, 458, 446]
[507, 492, 504]
=> 492

cache[output]
[87, 86, 84, 95, 96, 99, 111, 115, 116, 117, 107, 106, 103, 101, 96, 95, 93, 90, 88]
[175, 171, 171, 170, 163, 171, 173, 176, 174, 178, 178, 175]
[256, 248, 246, 247, 241, 240, 239, 243, 246, 247, 252, 242, 243, 259, 257]
[328, 326, 324, 322, 323, 327, 325, 322]
[402, 403, 396]
[455, 458, 456]
[517, 502, 504]
=> 502

cache[not optimized]
[87, 86, 84, 101, 102, 109, 121, 129, 128, 127, 121, 122, 111, 111, 96, 97, 99, 96, 88]
[175, 173, 173, 170, 163, 191, 189, 188, 174, 178, 184, 175]
[260, 248, 252, 251, 241, 240, 239, 243, 246, 247, 252, 254, 255, 261, 261]
[328, 326, 324, 336, 333, 337, 337, 334]
[402, 413, 406]
[465, 468, 456]
[517, 502, 514]
=> 502

cidx
[8, 9, 13, 14, 15, 20, 23, 26, 27, 32, 34, 39, 40, 44, 49, 50, 51, 54, 57, 58, 60, 65, 66, 69, 71, 80, 81, 83, 84, 86]
[3, 4, 6, 21, 22, 25, 37, 41, 42, 45, 55, 56, 59, 61, 76, 77, 79, 82, 88]
[1, 5, 7, 10, 17, 33, 35, 38, 64, 68, 74, 85]
[0, 12, 16, 19, 29, 30, 31, 43, 46, 47, 52, 62, 67, 87, 89]
[2, 24, 36, 48, 53, 73, 75, 78]
[18, 63, 70]
[11, 28, 72]

"""