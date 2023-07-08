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

    // 패턴 끝 도달
    if (pos == p.size()) 
    {
        // 패턴과 타깃 둘다 끝에 도달해야 매칭 성공!
        if (pos == t.size()) return 1;
        else return 0;
    }

    if (p[pos] == '*')
    {
        // k : 0 ~ (t.size() - pos) 하나도 없는 경우 포함
        for (int k = pos; k <= t.size(); k++)
        {
            // 문자열.substr(시작 index, 길이) <길이 생략시 끝까지>
            if(match(p.substr(pos+1), t.substr(k))) return true;
        }
    }
    return false;
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
            // if (match(p,t)) cout << t << "\n";
            cout << match(p,t) << endl;
        }
    }
}