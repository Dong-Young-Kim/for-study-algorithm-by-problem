// 이분법을 통한 문제 해결
// 수행시간 O(log(MAXGAME))

#include <iostream>
#include <math.h>

using namespace std;

// 최대로 수행 가능한 게임 수 20억 (long long 자료형 사용)
long long MAXGAME = 2000000000;

long long calc (long long G, long long W)
{
    const int currentRatio = (W * 100) / G;
    // 20억회 이상 승리해도 승률 변화가 없는 경우를 사전 검사함
    // cout << " current  ratio " << ((W * 100) / G) << endl;
    // cout << " after 2B ratio " << ((W + 2000000000) * 100) / (G + 2000000000) << endl;
    if (currentRatio == ((W + MAXGAME) * 100) / (G + MAXGAME)) return -1;

    long long lo = 0, hi = MAXGAME;

    while(hi - lo > 1) // 답을 찾을때 까지.. (hi와 lo가 1 차이날떄까지..)
    {
        long long mid = (hi + lo) / 2;
        if (currentRatio == ((W + mid) * 100) / (G + mid))
        //mid 번 게임을 더 시행했을 떄 승률이 같다면 (mid를 키워야)
        {
            lo = mid;
        } else // 승률이 다르다면 (mid를 줄여야)
        {
            hi = mid;
        }

    }

    return hi;
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