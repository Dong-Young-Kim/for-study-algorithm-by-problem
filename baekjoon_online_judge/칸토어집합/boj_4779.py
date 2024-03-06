# boj_4779 : 칸토어 집합

# 칸토어 집합을 출력하는 문제

# 칸토어 집합은 다음과 같은 방법으로 만들 수 있다.
# 1. 길이가 N인 선을 그린다.
# 2. 이 선을 3등분한다.
# 3. 세 개의 선 중 가운데 선을 제거한다.
# 4. 남은 두 선에 대해 2번 과정을 반복한다.

"""
3^N 만큼의 길이를 만들고 중간을 비우는 방식과
N=1 까지를 재귀적으로 호출하여 출력값을 만드는 두 방식 모두 사용할 수 있을 것

lrucache를 사용하여 중복되는 값들을 저장하여 시간을 단축할 수 있을 것

이 문제는 종료조건이 없으므로 try except를 사용하여 종료조건을 만들어줄 것

https://www.acmicpc.net/board/view/28913

"""

import functools
@functools.lru_cache(maxsize=12)
def make_kantor(n):
    if n == 0:
        return '-'
    else:
        return make_kantor(n-1) + ' ' * (3 ** (n-1)) + make_kantor(n-1)
while(True): 
    try:
        N = int(input())
        print(make_kantor(N))
    except:
        break
