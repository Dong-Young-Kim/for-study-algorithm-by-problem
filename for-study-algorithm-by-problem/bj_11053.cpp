// pure LIS (DP)

#include <iostream>
#include <memory.h>
using namespace std;

int N;
int A[1000], cache[1001];

int find(int crnt)
{
    int & ret = cache[crnt + 1];
    if (ret != -1) return ret;

    int maxLength = 0;
    for (int next = crnt+1; next < N; ++next)
    {
        if (A[next] > (crnt == -1 ? -1 : A[crnt])) maxLength = max(maxLength, find(next));
    }
    return ret = (maxLength + 1);
}

int main()
{
        memset(cache, -1, sizeof(cache));
        cin >> N;
        for (int i = 0; i < N; ++i) cin >> A[i];
        cout << find(-1) - 1 << '\n';
}
