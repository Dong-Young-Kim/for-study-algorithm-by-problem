#include <iostream>
#include <vector>

using namespace std;

int waysToBuy(const vector<int> psumk)
{
    const int MOD = 20091101;
    int ret = 0;
    vector<long long> count(psumk.size(), 0);
    for(int i=0; i<psumk.size(); i++)
        count[psumk[i]]++;
    for(int i=0; i<count.size(); i++)
        if(count[i] >= 2)
            ret = (ret + ((count[i] * (count[i] - 1)) / 2)) % MOD;
    return ret;
}

int maxBuys(const vector<int> psumk)
{
    vector<int> ret(psumk.size(), 0);
    vector<int> prev(psumk.size(), -1);
    for(int i=0; i<psumk.size(); i++)
    {
        if(i > 0)
            ret[i] = ret[i-1];
        else
            ret[i] = 0;
        int loc = prev[psumk[i]];
        if(loc != -1)
            ret[i] = max(ret[i], ret[loc] + 1);
        prev[psumk[i]] = i;
    }
    return ret.back();
}

int main()
{
    vector<int> psumk;
    
    int C;
    cin >> C;
    while(C--)
    {
        int N, K;
        cin >> N >> K;
        vector<int> dolls(N);
        for(int i=0; i<N; i++)
            cin >> dolls[i];
        psumk.clear();
        psumk.push_back(0);
        for(int i=0; i<N; i++)
            psumk.push_back((psumk.back() + dolls[i]) % K);
        cout << waysToBuy(psumk) << " " << maxBuys(psumk) << endl;
    }
    return 0;

}


// 한 번 주문할 수 있다면, 가능한 주문 방법은 몇 가지인가? -> 부분합이 k로 나누어지는 방법 찾기
// psumk[]를 mod(k)된 값을 저장한다.

// 여러 번 주문할 수 있다면, 주문이 겹치지 않게 최대 몇 번 주문할 수 있는가? 
//(주문이 겹친다는 것은 어떤 두 주문에 같은 번호의 인형 상자가 포함되는 것을 말한다.)