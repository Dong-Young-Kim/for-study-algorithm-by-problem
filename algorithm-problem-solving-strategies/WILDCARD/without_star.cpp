// 와일드카드 '*'가 없다고 가정할 때의 문자 매칭 알고리즘

#include <iostream>
#include <string>

using namespace std;

bool match (const string & p, const string & t) 
// p과 t가 일치하는지 반환한다.
{
    int pos;
    for (pos = 0; pos < p.size() && pos < t.size(); pos++)
    {
        if (t[pos] != p[pos] && '?' != p[pos]) break;
    }

    // 패턴과 타깃 둘다 끝에 도달해야 매칭 성공!
    if (pos == p.size() && pos == t.size()) return true;
    else return false;
}

int main()
{
    int T;
    cin >> T;
    string p, t;
    while(T--)
    {
        int targerT;
        cin >> p >> targerT;
        while (targerT--)
        {
            cin >> t;
            if (match(p,t)) cout << t << "\n";
            // cout << match(p,t) << endl;
        }
    }
}