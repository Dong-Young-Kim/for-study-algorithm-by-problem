#include <iostream>

using namespace std;

const int MOD = 10000000; // 첨만
int cache[101][101];


int poly(int n, int first)
{
    if (n == first) return 1;

    int & ret = cache[n][first];
    if(ret != -1) return ret;

    int sum = 0;
    for (int i = 1; i <= n - first; ++i)
    {
        // sum = max(1,000,000,000) 이므로 오버플로우 x
        sum += ((first + i - 1) * poly(n - first, i)) % MOD;
        sum %= MOD;
    }
    return ret = sum;
}

int main()
{
    int T, N;
    cin >> T;

    while(T--)
    {
        memset(cache, -1, sizeof(cache));
        cin >> N;
        int sum = 0;
        for (int i = 1; i<= N; ++i)
        {
            sum += poly(N, i);
            sum %= MOD;
        }
        printf("%d\n", sum);
    }

}