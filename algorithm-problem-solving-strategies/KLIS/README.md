# KLIS
K-th Longest Increasing Sequence

## 문제
어떤 정수 수열에서 0개 이상의 숫자를 지우면 이 수열의 부분 수열 (subsequence) 를 얻을 수 있다. 예를 들어 10 7 4 9 의 부분 수열에는 7 4 9, 10 4, 10 9 등이 있다. 단, 10 4 7 은 원래 수열의 순서와 다르므로 10 7 4 9 의 부분 수열이 아니다.

어떤 부분 수열이 _단조 증가_할 때 이 부분 수열을 증가 부분 수열 (increasing subsequence) 라고 하며, 이 중 가장 긴 것을 최대 증가 부분 수열 (LIS, longest increasing subsequence) 라고 한다. 예를 들어, 5 20 21 22 8 9 10 의 최대 증가 부분 수열은 5 8 9 10 이다.

어떤 수열에는 LIS 가 두 개 이상 있을 수 있다. 예를 들어, 4 5 6 1 2 3 의 LIS 는 두 개가 있다.

모든 숫자가 서로 다른 (중복 숫자가 없는) 수열이 주어질 때, 이 수열의 LIS 중 사전 순서대로 맨 앞에서 k번째 있는 LIS 를 출력하는 프로그램을 작성하시오.

### 입력
입력의 첫 줄에는 테스트 케이스의 수 C (<= 50) 가 주어진다. 각 테스트 케이스의 첫 줄에는 수열에 포함된 원소의 수 N (<= 500) 과 K 가 주어진다. K 는 32비트 부호 있는 정수에 저장할 수 있다. 그 다음 줄에 N개의 정수로 수열이 주어진다. 각 정수는 1 이상 100,000 이하이며, 같은 수는 두 번 등장하지 않는다.

주어진 수열의 LIS 는 최소 K 개 있다고 가정해도 좋다.

### 출력
각 테스트케이스마다 두 줄을 출력한다. 첫 줄에는 LIS 의 길이 L 을 출력하고, 그 다음 줄에 L 개의 정수로 K번째 LIS 를 출력한다.

### 예제 입력

```
3
9 2
1 9 7 4 2 6 3 11 10
8 4
2 1 4 3 6 5 8 7
8 2
5 6 7 8 1 2 3 4
```

### 예제 출력
```
4
1 2 3 11
4
1 3 6 8
4
5 6 7 8
```

> 참고 : 오버플로우 발생에 유의하며 코드를 작성하자 (LIS의 수를 계산하는 부분 / K 이상의 값은 셀 필요가 없다.)

---

## 문제 이해

k 번쨰의 최적해를 구하는 문제 중 하나인 KLIS 문제이다.
문제를 해결하기 위해서는 LIS를 구하고, 모든 LIS를 찾은 후 정렬,
정렬된 LIS에서 k 번쨰 LIS를 찾는 과정을 포함해야 할 것이다.

LIS의 개수를 구하는 과정과 k 번쨰 LIS를 찾는 과정이 핵심이다.

LIS의 풀이는 [여기](../LIS/README.md)에 있다.


## 문제해결

해결 과정은 다음과 같다
1. LIS 문제를 풀어 최적 해를 찾는다.
    - 이 문제를 풀면 모든 index에 대해 현재 index로 부터 시작하는 LIS의 최적 해가 구해진다.
2. LIS의 최적 해의 수를 찾는다.
    - 이 문제를 풀면 모든 index에 대해 현재 index로 부터 시작하는 LIS의 수를 구할 수 있다.
3. LIS를 재구성하여 k 번쨰 LIS를 찾는다.

### LIS 구현
우선 LIS의 코드를 보자

```cpp
int lis(int crnt)
{
    // 1. 기저사례
    // if (crnt == N) return 0; (없어도 된다)

    // 2. 캐시확인
    int & ret = cache[crnt + 1]; // -1 index로 인해서 한 칸씩 밀어서 cache를 사용
    if (ret != -1) return ret;

    int maxLength = 0;
    for (int next = crnt+1; next < N; ++next)
    {
        // crnt가 -1 이면 error가 발생하므로 crnt == -1이면 가상의 최소값인 -1로 값을 대치한다.
        if (A[next] > (crnt == -1 ? -1 : A[crnt])) maxLength = max(maxLength, find(next));
    }
    return ret = (maxLength + 1); // 자신의 길이를 포함하여 리턴 : +1 한 값
}
```

LIS() : crnt부터 시작하는 수열에 대한 증가 수열의 최대 길이


### count 구현

1. 기저사례

기저 사례가 무엇인지 잘 생각해보자

```cpp
if (crnt == N-1) return 1; // x
```

단순하게, 배열에 끝에만 도달하는 경우만 base case라고 생각하면 안된다

```cpp
if (lis(crnt) == 1) return 1; // o
```

lis의 길이가 1인 경우가 모두 기저사례이다. 이유는 LIS의 길이가 1이라는 뜻은 A[i]로 유일하게 LIS가 구성되는 경우이며, 이 경우 만들 수 있는 총 LIS의 수는 유일하기 때문이다. 따라서 LIS의 길이가 1인 경우 count 함수의 리턴값은 1이다.

2. 이외의 경우

```cpp
if (A[next] > (crnt == -1 ? -1 : A[crnt])
    && lis(crnt) == lis(next) + 1) 
{
    ret += count(next);
}
```

count(crnt)(A[crnt]를 포함하여 만들 수 있는 LIS의 가짓수)는, 다음 조건을 만족하는 count(next)(A[next] )의 합이다.

1. A[crnt] < A[next]
2. lis(crnt) == lis(next) + 1

위 두 조건을 만족하면 A[crnt] -> A[next]의 순서대로 LIS를 구성한다.

### kthLIS 구현

```cpp
void calcKth(int crnt, int skip, vector<int> & kthLIS)
{
    vector<pair<int, int>> nextNumbers; // <A[next], next>
    for (int next = crnt+1; next < N; ++next)
    {
        if (A[next] > (crnt == -1 ? -1 : A[crnt])
            && lis(crnt) == lis(next) + 1)
        {
            // 다음에 올 수 있는 수를 모두 추가한다.
            nextNumbers.push_back(make_pair(A[next], next));
        }
    }

    // 추가한 수를 정렬한다.
    sort(nextNumbers.begin(), nextNumbers.end());

    // skip을 줄여가면서 조건에 맞는 A[next]를 찾는다.
    for (pair<int, int> nextNumber : nextNumbers)
    {
        if (skip < count(nextNumber.second))
        {
            kthLIS.push_back(nextNumber.first);
            calcKth(nextNumber.second, skip, kthLIS);
            break;
        }
        skip -= count(nextNumber.second);
    }
}
```

위 코드는 -1 index부터 호출될 것을 가정하고 작성되었다.

```cpp
// 호출부
vector<int> kthLIS; // k 번쨰 LIS를 저장할 vector
calcKth(-1, skip, kthLIS);
```

k번째 값을 찾는 원리를 이용하여 문제를 해결한다.
k번쨰 내용을 찾는 기본 원리는 [이 코드](../MORSE/morse.cpp)의 calcKth를 참고하자

문제를 해결하는 기본 원리는 아래와 같다

1. skip해야할 수를 정한다. skip = K-1
2. count[crnt] = sum(count[next])로 이루어진 점을 이용하여 조건에 맞도록 "skip -= count[next]" 해가면서 다음에 와야할 적절한 수를 찾는다.

이 문제에서 k 번쨰 LIS를 구할 떄 주의해야 할 부분은 LIS의 사전순서는 index의 순서가 아니라는 것이다. 처음 이 점을 잘못 생각하여 이와 같이 잘못 코드를 잘못 작성하였다.

```cpp
// 이 함수는 LIS의 index를 사전 순서대로 정렬했을때 k 번쨰를 찾는다
void calcKthIndexOrder(int crnt, int skip, vector<int> & kthLIS)
{
    for (int next = crnt+1; next < N; ++next)
    {
        if (A[next] > (crnt == -1 ? -1 : A[crnt])
            && lis(crnt) == lis(next) + 1)
        {
            if (skip < count(next))
            {
                kthLIS.push_back(A[next]);
                calcKthIndexOrder(next, skip, kthLIS);
                break;
            }
            skip -= count(next);
        }
    }
}
```

사전순서대의 k번째 LIS를 탐색하는 핵심 원리는 

1. 다음 올 수와 index를 함께 pair 형식으로 자장해 놓고, 
2. 다음 올 수를 기준으로 정렬한 후, 
3. 다음에 올 수를 확정하는 것이다.

pair 자료형을 sort 함수에 사용하면 first 원소를 기준으로 정렬되므로 A[next]를 first로, next(index)를 second로 구성하여 pair를 만들면 된다.

### Test Case

|i|-1|0|1|2|3|4|5|6|7|
|-|-|-|-|-|-|-|-|-|-|
|A[i]|-inf|5|1|6|4|3|2|8|7|
|LIS(i)|4|3|3|2|2|2|2|1|1|
|count(i)|10|2|8|2|2|2|2|1|1|

```
8 5
5 1 6 4 3 2 8 7
```

---

***본 문제의 출처는 '알고스팟(https://algospot.com)'에 있으며, 풀이 소스코드의 일부는 '알고리즘 문제해결 전략'을 참고하여 작성되었습니다.***
