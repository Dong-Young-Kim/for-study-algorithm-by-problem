// 와일드카드 '*'가 없다고 가정할 때의 문자 매칭 알고리즘

#include <iostream>
#include <string>

using namespace std;

int cache[101][101];
string p, t;

bool match (int pi, int ti) 
// p와 t의 사작 index를 전단 받도록 수정
{
    // 1. 기저사례 처리
    // (이 경우 기저사례는 아래 계산 과정에서 처리된다)

    // 2. 캐시확인
    int & ret = cache[pi][ti];
    if (ret != -1) return ret;

    // 3. 계산
    for (pi, ti; pi < p.size() && ti < t.size(); pi++, ti++)
    // pos 변수 대신 pi와 ti를 사용
    {
        if (t[ti] != p[pi] && '?' != p[pi]) break;
    }

    // 패턴 끝 도달
    if (pi == p.size()) 
    {
        // 패턴과 타깃 둘다 끝에 도달해야 매칭 성공!
        if (ti == t.size()) return ret = 1;
        else return ret = 0;
    }

    if (p[pi] == '*')
    {
        // k : ti ~ t.size()
        for (int k = ti; k <= t.size(); k++)
        {
            if(match(pi+1, k)) return ret = 1;
        }
    }
    return ret = 0;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int targerT;
        cin >> p >> targerT;
        while (targerT--)
        {
            memset(cache, -1, sizeof(cache)); // 위치 주의
            cin >> t;
            if (match(0,0)) cout << t << "\n";
            // cout << match(0,0) << endl;
        }
    }
}