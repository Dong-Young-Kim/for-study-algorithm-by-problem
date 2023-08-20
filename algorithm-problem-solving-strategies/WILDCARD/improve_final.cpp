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
    // (이 문제의 경우 기저사레는 아래 계산 과정에서 처리된다)

    // 2. 캐시확인
    int & ret = cache[pi][ti];
    if (ret != -1) return ret;

    // 3. 계산
    if(pi < p.size() 
        && ti < t.size() 
        && (t[ti] == p[pi] || '?' == p[pi])) 
    // 한 글자가 범위 내로 매칭이 가능하다면 다음 글자를 검사하고 그 결과를 반환한다.
    {
        return ret = match(pi+1, ti+1);
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
        if(match(pi+1, ti)|| match(pi, ti+1))
        // 여기에서 범위 검사를 해주어야 하는가?
        // 1. pi가 끝에 도달한다면? 재귀함수 pi 범위 검사에서 걸러짐 -> 문제없음
        // 2. ti가 끝에 도달한다면 -> 모든 if 문에 포함되지 못하고 0을 return -> 문제없음
        {
            return ret = 1;
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