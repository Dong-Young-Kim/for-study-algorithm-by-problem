# 합친 LIS

## 문제
어떤 수열에서 0개 이상의 숫자를 지운 결과를 원 수열의 부분 수열이라고 부릅니다. 예를 들어 '4 7 6'은 '4 3 7 6 9'의 부분 수열입니다. 중복된 숫자가 없고 오름 차순으로 정렬되어 있는 부분 수열들을 가리켜 증가 부분 수열이라고 부르지요. 예를 들어 '3 6 9'는 앞의 수열의 증가 부분 수열입니다.

두 개의 정수 수열 A 와 B 에서 각각 증가 부분 수열을 얻은 뒤 이들을 크기 순서대로 합친 것을 합친 증가 부분 수열이라고 부르기로 합시다. 이 중 가장 긴 수열을 합친 LIS(JLIS, Joined Longest Increasing Subsequence)이라고 부릅시다. 예를 들어 '1 3 4 7 9' 은 '1 9 4' 와 '3 4 7' 의 JLIS입니다. '1 9' 와 '3 4 7' 을 합쳐 '1 3 4 7 9'를 얻을 수 있기 때문이지요.

A 와 B 가 주어질 때, JLIS의 길이를 계산하는 프로그램을 작성하세요.

### 입력
입력의 첫 줄에는 테스트 케이스의 수 c ( 1 <= c <= 50 ) 가 주어집니다. 각 테스트 케이스의 첫 줄에는 A 와 B 의 길이 n 과 m 이 주어집니다 (1 <= n,m <= 100). 다음 줄에는 n 개의 정수로 A 의 원소들이, 그 다음 줄에는 m 개의 정수로 B 의 원소들이 주어집니다. 모든 원소들은 32비트 부호 있는 정수에 저장할 수 있습니다.

##3 출력
각 테스트 케이스마다 한 줄에, JLIS 의 길이를 출력합니다.

### 예제 입력

```
3
3 3
1 2 4
3 4 7
3 3
1 2 3
4 5 6
5 3
10 20 30 1 2
10 20 30
```

### 예제 출력

```
5
6
5
```

<br>

---

<br>

## 문제 해결

### 문제 이해

단순히 두 수열의 LIS를 각각 구하고 두 수열을 합하는 방식으로는 문제를 해결할 수는 없다.

정답인 수열의 특성
 - 각각의 A와 B는 LIS를 만족해야 하며
 - A와 B 수열을 번갈아가면 나타날 수 있다.
 - merge sort의 merge과정과 비슷함


### 재귀 호출

LIS에서 index "'k'에서 부터 시작하는 최대 부분 증가 수열의 아이디어"를 통해 문제를 해결하였다.

JLIS에서도 이와 동일하게 "두 수열 A와 B 각각 'k', 'l' 에서 부터 시작하는 최대 부분 증가 수열의 아이디어"를 통해 문제를 해결할 수 있다. 즉 cache에는 index가 k,l일떄의 jlis 값을 기록해 놓고


이 방식이 부분 최대 구조를 만족하는가

1. A를 고정하고 B를 탐색
2. B를 고정하고 A를 탐색

### 예외처리

> 두 수가 같은 경우는 어떻게 해야 하는가

find(i,j)에서 A[i], B[j] 가 같은 경우는 존재할 수 없다.
- A[i]와 B[j]를 반드시 포함해야 하기 떄문



### 오류 잡기

``` cpp
int find(int crntA, int crntB)
{
    // 1. 기저사례
    if (A[crntA] == B[crntB]) return 1;
    if (crntA == M-1 && crntB == N-1) return 2;

    int maxValue = max(A[crntA], B[crntB]);
    int maxLength = 0;

    for (int next = crntA+1; next < M; ++next)
    {
        if (A[next] > maxValue) maxLength = max(maxLength, find(next, crntB));
    }
    for (int next = crntB+1; next < N; ++next)
    {
        if (B[next] > maxValue) maxLength = max(maxLength, find(crntA, next));
    }

    return maxLength + 1;
}
```

LIS를 응용하여 위와 같이 재귀 함수를 구현했다.

위 경우 모든 기저 사례를 전부 처리하지 못해 원하는 답 보다 적게 출력될 수 있는 문제가 있었다. 

```
2
3 4
4 5
```
사례의 답을 구하는 과정에서 find(0,0) -> find(0,1) 까지만 호출되고 답이 구해지지만, find(2,2) 까지 전부 호출 될 것으로 가정하여 답을 제대로 구하지 못했다. 이 문제를 해결하여 아래와 같이 코드를 수정할 수 있었다.

```cpp
int find(int crntA, int crntB)
{
    // 1. 기저사례
    if (A[crntA] == B[crntB]) return 1;
    if (crntA == M-1 && crntB == N-1) return 2;

    int maxValue = max(A[crntA], B[crntB]);
    // 두 인수가 같은 경우를 사전에 처리했으므로 최소 길이를 2로 가정할 수 있다.
    // 다만 최종 return 전에 +1 되므로 1로 maxLength를 초기화해야한다.
    int maxLength = 1;

    for (int next = crntA+1; next < M; ++next)
    {
        if (A[next] > maxValue) maxLength = max(maxLength, find(next, crntB));
    }
    for (int next = crntB+1; next < N; ++next)
    {
        if (B[next] > maxValue) maxLength = max(maxLength, find(crntA, next));
    }

    return maxLength + 1;
}
```

위와 같은 경우에도 제대로 답을 구할 수 없다. 다음의 예시를 보자

```
3 3
1 2 4
3 4 7
```

위 예시에서 정답은 1,2,3,4,7이 포함되어 5가 출력되어야 하지만 위 코드를 이용하면 4가 나온다.

이는 find(0,0) 부터 호출이 시작되어 maxValue가 3으로 고정되어 버리고 이보다 작은 수인 2가 포함될 해결과정에서 포함될 수 없기 떄문이다.

즉 B의 원소가 하나도 포함되지 않은 상태에서 A의 LIS를 구할 수 있어야 한다.

---

***본 문제의 출처는 '알고스팟(https://algospot.com)'에 있으며, 풀이 소스코드의 일부는 '알고리즘 문제해결 전략'을 참고하여 작성되었습니다.***
