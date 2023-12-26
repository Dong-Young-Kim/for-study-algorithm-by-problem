// 색종이 만들기

#include <iostream>

using namespace std;

bool board[128][128];

pair<int, int> calc(int x, int y, int N)
{
    if(N == 1)
    {
        return make_pair(!board[x][y], board[x][y]);
    }

    // 모두 같은 값인지 확인
    bool allOne = 1, allZero = 1;
    for (int i = x; i < x+N; ++i)
    {
        for (int j = y; j < y+N; ++j)
        {
            board[i][j] ? allZero = 0 : allOne = 0;

            if (!allOne && !allZero) break; // 시간 단축을 위한 조건 (없어도 무관)
        }
    }

    if (allOne) return make_pair(0, 1);
    if (allZero) return make_pair(1, 0);

    pair<int, int> tmp, sum = make_pair(0, 0);

    tmp = calc(x, y, N/2);
    sum.first += tmp.first; sum.second += tmp.second;
    tmp = calc(x+N/2, y, N/2);
    sum.first += tmp.first; sum.second += tmp.second;
    tmp = calc(x, y+N/2, N/2);
    sum.first += tmp.first; sum.second += tmp.second;
    tmp = calc(x+N/2, y+N/2, N/2);
    sum.first += tmp.first; sum.second += tmp.second;

    return sum;

}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N*N; ++i)
    {
        cin >> board[i/N][i%N];
    }

    pair<int, int> res = calc(0, 0, N);
    printf("%d\n%d\n", res.first, res.second);

}

/*
재귀를 통해서 해결

반환값 : 색종이의 수 pair<int, int> (흰색, 파란색)
입력 값 : 감사할 위치 좌표
기저 조건 : 색종이의 크기가 1이면 1을 반환

1. 모두 1인지 확인 -> 1이면 1 반환
2. 모두 0인지 확인 -> 0이면 0 반환
3. 모두 같은 색이 아니면 아니면 4등분해서 재귀호출 결과의 합을 반환

+ N이 1이면 1또는 0을 무조건 반환

*/

// bitmask를 사용하면 검색시간의 단축이 가능할 것
