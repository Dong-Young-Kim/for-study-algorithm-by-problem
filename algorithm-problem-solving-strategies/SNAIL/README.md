# 달팽이

## 문제

깊이가 n 미터인 우물의 맨 밑바닥에 달팽이가 있습니다. 이 달팽이는 우물의 맨 위까지 기어올라가고 싶어하는데, 달팽이의 움직임은 그 날의 날씨에 좌우됩니다. 만약 비가 내리면 달팽이는 하루에 2미터를 기어올라갈 수 있지만, 날이 맑으면 1미터밖에 올라가지 못합니다.

여름 장마가 찾아와, 앞으로 m 일간 각 날짜에 비가 올 확률이 정확히 75%일 전망입니다. m 일 안에 달팽이가 우물 끝까지 올라갈 확률을 계산하는 프로그램을 작성하세요.

### 입력
입력의 첫 줄에는 테스트 케이스의 수 C(1≤C≤50) 가 주어집니다. 그 후 각 줄에 우물의 깊이 n(1≤n≤1000)과 장마 기간의 길이 m(1≤m≤1000) 이 주어집니다.

### 출력
각 테스트 케이스마다 한 줄에 m일 안에 달팽이가 우물을 탈출할 수 있을 확률을 출력합니다. 10−7 이하의 상대/절대 오차가 있는 답은 정답으로 인정됩니다.

### 예제 입력
4
5 4
5 3
4 2
3 2
### 예제 출력
0.9960937500
0.8437500000
0.5625000000
0.9375000000

<br>

--- 

<br>

## 뮨제 해결

### 아이디어

문제의 입력으로 1. 달팽이가 올라가는 전체 일수와, 2. 우물의 깊이가 주어진다. 날짜가 지날 수록 남은 날짜와, 오르는 거리가 줄어든다. 즉 앞으로 남은 거리와 남은 날 수만 정해진다면, 지금까지 올라온 과정에 상관 없이 우물을 오를수 있는 여부가 결정된다. 이 둘을 함수의 입력값으로 결정 한 후 재귀 호출하거나, 남은 일짜가 0일때 부터 m일때까지 반복호출 한다면 문제를 해결할 수 있다.

```
climb(remainDays, toClimb)
```

앞으로 remainDays일동안 오를수 있고 toClimb 만큼 남았을 떄 오를 수 있을 확률

``` 
climb(remainDays, toClimb) = 0.75 * (climb(remainDays - 1, toClimb - 2)) + 0.25 * (climb(remainDays - 1, toClimb - 1))

```

비가 오는 경우 2m 날씨가 맑은 경우 1m 올라갈 수 있다.

비가 온 날과 오지 않은 날 모두의 사례를 계산하고 이를 각각의 확률대로 곱합으로서 현재값을 계산할 수 있다.

<br>

## 추가

memset을 이용하여 배열을 초기화 할 수 있다. 다만 memset 함수는 1Byte 단위로 배열을 초기화하므로 char형 배열을 초기화 하거나, int 형 중에서 모두 000으로 초기화되는 0과 111로 초기화되는 -1의 경우는 사용할 수 있으나, 부동 소수점을 사용하는 double type의 배열은 원하는 값으로 초기화가 불가능하다.
실제로 아래와 같이 double type의 배열을 초기화 하는 경우에는 NaN으로 전체 배열 값이 바뀌어버린다.

```
memset(cache, -1, sizeof(cache));
```

따라 동적 계획법 문제를 해결할 떄 cache에 double 형을 저장해 사용하고자 할때는 fill이나 fill_n 함수를 사용하는 것이 바람직하다.

### fill,  fill_n 함수

**사용법**
```
fill(시작주소,끝나는주소,초기화값)
fill_n(시작주소,크기,초기화값)
```

1차원 배열
```
fill(arr, arr+10, 7);
fill(arr, arr+10, 7);
```

2차원 배열
```
fill(&arr[0][0], &arr[ROW -1][COL], 7)
fill_n(&arr[0][0], ROW*COL, 7)
fill_n(arr[0], ROW*COL, 7)
```

벡터
```
fill (v.begin(), v.end(), 7);
fill_n (v.begin(), 10, 7);
```

2차원 배열의 경우에는 배열의 사작 수소가 아니라 첫 원소의 시작 주소를 넣는 것에 주의해야 한다.

> arr과 &arr[0][0]은 실제 지칭하는 메모리의 위치는 동일하지만 갖는 의미가 다르다
>
> - arr: arr은 2차원 배열의 이름 자체를 가리키는 포인터이다. 이는 첫 번째 행의 시작 주소를 가리키는 것과 동일
>
> - arr[0]: arr[0]은 2차원 배열의 첫 번째 행을 가리키는 포인터이다. arr[0]은 &arr[0][0]과 동일한 값을 가리키며, 이는 첫 번째 요소의 주소를 가리킴


---

***본 문제의 출처는 '알고스팟(https://algospot.com)'에 있으며, 풀이 소스코드의 일부는 '알고리즘 문제해결 전략'을 참고하여 작성되었습니다.***