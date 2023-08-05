#include<iostream>
using namespace std;

int Rd, Bl;

int R, B, N;
int cache[480][50001]; //[현재까지 그린 원의 개수][사용한 빨간 페인트의 수]
const int MOD = 1000000007;


inline int calcBlue(int n, int red)
// 빨간 페인드틀 'red' 만큼 사용, 그린 원의 수가 'n' 일때 
// 사용한 파란 페인트의 양
{
    return n * (n + 1) / 2 - red;
}

int num(int n, int red)
// 페인트를 'red' 만큰 사용하고
// n개의 원을 그렸을 때
// 색칠 가능한 종류
{
    // 0. 사전 계산
    int blue = calcBlue(n, red);

    // 1. 기저사례
    if (red > R || blue > B) return 0; // 페인트가 모자람

    // 2. 캐시 확인
    int & ret = cache[n][red];
    if (ret != -1) return ret;

    // 3. 계산
    return ret = (1 + num(n+1, red+n+1) + num(n+1, red)) % MOD;
}
bool fflag = false;
int wrongCode()
{

        if(fflag == false) 
        {
            memset(cache, -1, sizeof(cache));
            fflag = true;
        }
        R = Rd; B=Bl;
        // cin >> R >> B;
        // 하나도 그리지 않는 경우는 없으므로 num(0,0)은 호출할 수 없다.
        return ((num(1,1) + num(1,0)) % MOD);
        // cout << num(1,1) + num(1,0) << endl;

}




#include <vector>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

vector<ll> v[100004];
vector<ll> pfx[100004];
bool flag = false;

int rightCode() {
    ll idx, inc;
    if(flag == false)
    {
        flag = true;
        ios::sync_with_stdio(false);
        cin.tie(nullptr), cout.tie(nullptr);

        idx = 3, inc = 2;
        v[1].push_back(1), v[1].push_back(1);
        pfx[1].push_back(1), pfx[1].push_back(2);
        while (idx <= 100000) {
            v[inc].push_back(1);
            for (int i=1; i<idx; i++) {
                ll res = 0;
                if (i >= inc) res += v[inc-1][i-inc];
                if (i <= idx - inc) res += v[inc-1][i];
                v[inc].push_back(res % MOD);
            }
            v[inc].push_back(1);

            pfx[inc].push_back(1);
            for (int i=1; i<=idx; i++) {
                ll tmp = pfx[inc][i-1];
                pfx[inc].push_back((tmp + v[inc][i]) % MOD);
            }
            inc += 1, idx += inc;
        }
    }

    // int T; cin >> T;
    // while (T--) {
        ll a = Rd, b = Bl;
        idx = 1, inc = 1;
        ll res = 0;
        while (idx <= a + b) {
            if (idx <= a && idx <= b) {
                ll tmp = ll(pfx[inc].size()) - 1;
                res = (pfx[inc][tmp] + res) % MOD;
            }
            else {
                ll tmp1 = min(a, ll(pfx[inc].size()) - 1);
                ll tmp2 = max(-1ll, ll(pfx[inc].size()) - b - 2);
                if (tmp2 == -1) res = (pfx[inc][tmp1] + res) % MOD;
                else res = (pfx[inc][tmp1] - pfx[inc][tmp2] + res + MOD) % MOD;
            }
            inc += 1, idx += inc;
        }
        return res;
        // cout << res << "\n";
    // }
    return 0;
}



void makeTC()
{
    Rd = rand() % 10000+40000;
    Bl = rand() % 10000+40000;
}

int main()
{
    int T = 0;

    cout << "start\n";

    while(1)
    {
        makeTC();

        int right, wrong;
        right = rightCode();
        wrong = wrongCode();
        if (right != wrong) 
        {
            printf("%d %d \n", Rd, Bl);

            cout << "right Ans = " << right << endl;
            cout << "worng Ans = " << wrong << endl;
            cout << "======================" << endl;
            break;
        }
        T++;
        if(T%100 == 0) cout << "T = " << T << endl;
    }
    return 0;
}

/*
start
101027544 470196557 471123602 
right Ans = 109
worng Ans = 41


101027544 
470196557 
471123602 

*/
