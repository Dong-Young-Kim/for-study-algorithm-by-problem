# boj_18870 : 좌표 압축

"""
좌표 압축은 수의 대소관계만 파악하고자 하는 경우
수의 법위를 줄이기 위해서 사용한다.
"""


import sys
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))

# 1. 정렬, 중복제거
sorted_arr = sorted(list(set(arr)))

# 2. 값->인덱스를 반환하는 dict
compressed_arr = {sorted_arr[i]: i for i in range(len(sorted_arr))}

# 3. 출력
print(*[compressed_arr[i] for i in arr])
