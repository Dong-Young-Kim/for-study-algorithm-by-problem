// 수식적 계산을 통한 문제 해결
// 수행시간 O(1)

#include <iostream>
#include <math.h>

using namespace std;

// 최대로 수행 가능한 게임 수 20억 (long long 자료형 사용)
long long MAXGAME = 2000000000;

long long calc (long long G, long long W)
{
    // 20억회 이상 승리해도 승률 변화가 없는 경우를 사전 검사함
    // cout << " current  ratio " << ((W * 100) / G) << endl;
    // cout << " after 2B ratio " << ((W + 2000000000) * 100) / (G + 2000000000) << endl;
    if (((W * 100) / G) == ((W + MAXGAME) * 100) / (G + MAXGAME)) return -1;

    long long goalRatio = (W * 100) / G + 1;
    // cout << " goal     ratio " << goalRatio << endl;

    double winAdd;
    winAdd = ((double)((goalRatio * G) - (100 * W))) / ((double)(100 - goalRatio));

    // cout << " win Add " << winAdd << endl;
    return ceil(winAdd);
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        long long G, W;
        cin >> G >> W;
        printf("%lld\n", calc(G, W));
    }
}