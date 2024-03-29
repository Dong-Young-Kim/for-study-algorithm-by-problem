# 게임판 덮기

## 문제

H*W 크기의 게임판이 있습니다. 게임판은 검은 칸과 흰 칸으로 구성된 격자 모양을 하고 있는데 이 중 모든 흰 칸을 3칸짜리 L자 모양의 블록으로 덮고 싶습니다. 이 때 블록들은 자유롭게 회전해서 놓을 수 있지만, 서로 겹치거나, 검은 칸을 덮거나, 게임판 밖으로 나가서는 안 됩니다. 위 그림은 한 게임판과 이를 덮는 방법을 보여줍니다.

게임판이 주어질 때 이를 덮는 방법의 수를 계산하는 프로그램을 작성하세요.

### 입력

력의 첫 줄에는 테스트 케이스의 수 C (C <= 30) 가 주어집니다. 각 테스트 케이스의 첫 줄에는 2개의 정수 H, W (1 <= H,W <= 20) 가 주어집니다. 다음 H 줄에 각 W 글자로 게임판의 모양이 주어집니다. # 은 검은 칸, . 는 흰 칸을 나타냅니다. 입력에 주어지는 게임판에 있는 흰 칸의 수는 50 을 넘지 않습니다.

### 출력

한 줄에 하나씩 흰 칸을 모두 덮는 방법의 수를 출력합니다.

### 예제 입력

```
3 
3 7 
#.....# 
#.....# 
##...## 
3 7 
#.....# 
#.....# 
##..### 
8 10 
########## 
#........# 
#........# 
#........# 
#........# 
#........# 
#........# 
########## 
```

### 예제 출력

```
0
2
1514
```

<br>

---

## 문제 해결

### board 구현

2차원 vector 자료 구조를 통해 입력 받은 board를 구현

검은 칸과 블럭으로 채워진 칸은 1로, 흰 칸과 아직 채워지지 않은 칸은 0으로 표현

|case|값|
|-|-|
|검은 칸|1|
|블럭으로 채워진 칸|1|
|흰 칸|0|
|아직 채워지지 않은 칸|0|

<br>

### 재귀를 통한 완전 탐색

1. 흰색 칸의 수를 구함
1. 흰 색 칸의 수를 3으로 나눠 놓아야 할 총 즐럭 수를 구함
1. 한 블럭을 내려놓고 재귀 함수를 통해서 나머지 내려놓아야 할 블럭을 계산

<br>

### 중복 해결

무작위로 블럭을 내려놓는 방식으로 문제를 해결하면 동일한 블럭 배치더라도 다른 방법으로 계산될 수 있다.
이 경우에는 실제 답보다 더 큰 수를 답으로 반환하게 된다.

이를 막기 위해서는 "특정한 순서대로 답을 생성하도록" 강제하여 문제를 해결할 필요가 있다.

여기서는 가장 좌측 상단에 있는 빈 칸부터 채워나가는 방식을 통해 중복 문제를 해결한다.

> 이때 가장 최측 상단의 빈칸을 하나의 블럭으로 채우는 경우는 4가지 존재한다.

<br>

### cover() 함수 구현

문제를 해결하고 재귀 호출에 이용될 cover 함수를 구현한다.

1. 입력된 board 에서 가장 좌측 상단에 있는 칸을 찾는다 (좌측 상단부터 전수조사)
    - 이때 모든 칸을 채운 것으로 판단되면 함수를 종료한다
1. 빈칸을 채울 수 있는 4가지 경우를 각각 시도하고, 각각 뎦을 수 있다면 재귀 호출한다.
1. 덮었던 블록을 치운다


- 문제 해결 과정에서 한 칸에 블럭을 중복해서 놓는 경우가 발생하는데 이때는 board[i][j]의 값이 1 이상이 되면서 블럭이 겹쳐서 쌓아진 것을 표현한다.

<br>

### set() 함수 구현

블럭을 놓는 것과 블럭을 제거하는 행위는 동작과정이 상당히 유사하므로 set() 함수로 동시에 구현할 수 있다.

set 함수는 블럭을 덮을 수 있는지 판단하고 블럭을 놓을 수 있는 경우 true를 그렇지 않은 경우는 false를 반환하는 역할을 수행하고,
놓았던 블럭을 다시 제거하는 역할도 coverFlag 파라미터를 통해 수행하게 된다.

> 이때 블럭을 덮을 때 board를 벗어나는 경우 vector의 범위를 벗어날 수 있으므로 주의

board 밖으로 블럭이 벗어나는 경우, 이미 블럭이 놓인 위치에 블럭을 놓는 경우, 검은색 칸을 덮는 경우
모두를 판단하여 set 함수에서 false를 반환할 수 있도록 해야한다.

## 추가

- 사전에 흰색 칸 개수를 세어 블럭을 모두 놓는 경우가 발생 가능한지 문제를 해결하지 않고 점검 가능하다.

- x, y 방향 주의

</br>

### basic test case

```
1
2 5
#...#
#...#

1
2 3
...
...

1
2 2
..
.#

```

---

***본 문제의 출처는 '알고스팟(https://algospot.com)'에 있으며, 풀이 소스코드의 일부는 '알고리즘 문제해결 전략'을 참고하여 작성되었습니다.***
