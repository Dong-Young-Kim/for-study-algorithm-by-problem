#include <iostream>

using namespace std;

int M, N;
int A[100], B[100];
int cache[101][101];

int find(int crntA, int crntB)
{
    // 1. 기저사례
    if (A[crntA] == B[crntB]) return 1;
    if (crntA == M-1 && crntB == N-1) return 2;

    int maxValue = max(A[crntA], B[crntB]);
    // 두 인수가 같은 경우를 사전에 처리했으므로 최소 길이를 2로 가정할 수 있다.
    // 다만 최종 return 전에 +1 되므로 1로 maxLength를 초기화해야한다.
    int maxLength = 1;

    for (int next = crntA+1; next < M; ++next)
    {
        if (A[next] > maxValue) maxLength = max(maxLength, find(next, crntB));
    }
    for (int next = crntB+1; next < N; ++next)
    {
        if (B[next] > maxValue) maxLength = max(maxLength, find(crntA, next));
    }

    return maxLength + 1;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        memset(cache, -1, sizeof(cache));
        cin >> M >> N;
        for (int i = 0; i < M; ++i) cin >> A[i];
        for (int i = 0; i < N; ++i) cin >> B[i];
                

        // 찾을 수열이 어디서부터 시작할 지 모르므로 모두 순회해야 한다.
        int maxLength = 0;
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j) 
                maxLength = max(maxLength, find(i,j));

        cout << maxLength << '\n';
    }
}
