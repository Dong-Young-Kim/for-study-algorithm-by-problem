# 쿼드 트리 뒤집기

### 문제
대량의 좌표 데이터를 메모리 안에 압축해 저장하기 위해 사용하는 여러 기법 중 쿼드 트리(quad tree)란 것이 있습니다. 주어진 공간을 항상 4개로 분할해 재귀적으로 표현하기 때문에 쿼드 트리라는 이름이 붙었는데, 이의 유명한 사용처 중 하나는 검은 색과 흰 색밖에 없는 흑백 그림을 압축해 표현하는 것입니다. 쿼드 트리는 2N × 2N 크기의 흑백 그림을 다음과 같은 과정을 거쳐 문자열로 압축합니다.

![quadtree](https://github.com/Dong-Young-Kim/for-study-algorithm-by-problem/assets/72393686/e46e38a3-eafc-43d2-aaeb-698fcbd99b88)

- 이 그림의 모든 픽셀이 검은 색일 경우 이 그림의 쿼드 트리 압축 결과는 그림의 크기에 관계없이 b가 됩니다.
- 이 그림의 모든 픽셀이 흰 색일 경우 이 그림의 쿼드 트리 압축 결과는 그림의 크기에 관계없이 w가 됩니다.
- 모든 픽셀이 같은 색이 아니라면, 쿼드 트리는 이 그림을 가로 세로로 각각 2등분해 4개의 조각으로 쪼갠 뒤 각각을 쿼드 트리 압축합니다. 이때 전체 그림의 압축 결과는 x(왼쪽 위 부분의 압축 결과)(오른쪽 위 부분의 압축 결과)(왼쪽 아래 부분의 압축 결과)(오른쪽 아래 부분의 압축 결과)가 됩니다. 예를 들어 그림 (a)의 왼쪽 위 4분면은 xwwwb로 압축됩니다.

그림 (a)와 그림 (b)는 16×16 크기의 예제 그림을 쿼드 트리가 어떻게 분할해 압축하는지를 보여줍니다. 이때 전체 그림의 압축 결과는 xxwww bxwxw bbbww xxxww bbbww wwbb가 됩니다.

쿼드 트리로 압축된 흑백 그림이 주어졌을 때, 이 그림을 상하로 뒤집은 그림 을 쿼드 트리 압축해서 출력하는 프로그램을 작성하세요.

### 입력
첫 줄에 테스트 케이스의 개수 C (C≤50)가 주어집니다. 그 후 C줄에 하나씩 쿼드 트리로 압축한 그림이 주어집니다. 모든 문자열의 길이는 1,000 이하이며, 원본 그림의 크기는 220 × 220 을 넘지 않습니다.

### 출력
각 테스트 케이스당 한 줄에 주어진 그림을 상하로 뒤집은 결과를 쿼드 트리 압축해서 출력합니다.

### 예제 입력
```
4
w
xbwwb
xbwxwbbwb
xxwwwbxwxwbbbwwxxxwwbbbwwwwbb
```

### 예제 출력
```
w
xwbbw
xxbwwbbbw
xxwbxwwxbbwwbwbxwbwwxwwwxbbwb
```

<br>

---

<br>

## 문제 해결




--- 
### 추가

#### 함수에 iterator를 전달하는 방법

7_5.cpp 에서 decompress 함수 호출 시 아래와 같이 사용이 불가능하다

``` cpp
void decompress(std::string::iterator& it, int x, int y, int size);

...

decompress (compressed.begin(), 0, 0, MAX_SIZE);
```

비const 참조에 대한 초기 값은 lvalue여야 한다. 'compressed.begin()'는 임시 객체로 lvalue가 아니기 때문에 위와 같은 호출식은 사용할 수 없다.

<br>

``` cpp
void decompress(std::string::iterator& it, int x, int y, int size);

...

string::iterator it = compressed.begin();
decompress (it, 0, 0, MAX_SIZE);
```

compressed.begin()의 반환 값을 iterator 변수에 할당한 후, 해당 변수를 참조로 전달하는 방식을 사용하여 기능을 구현해야 한다.



#### char 자료형을 string 라턴값으로 전달하기

```cpp
string reverse(string::iterator & it)
{
    char cur_str = *it;
    it++;

    if(cur_str == 'b' || cur_str == 'w')
    {
        return string(1,cur_str);

        ...
    }
}

```

위와 같은 경우 char 자료형인 cur_str을 string 인 함수 리턴값에 맞게 전달해야 하는데 이때 string 객체 초기화 방법을 통해서 string 형으로 변환할 수 있다.