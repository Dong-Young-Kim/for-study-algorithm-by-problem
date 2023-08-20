#include <iostream>

using namespace std;

int N;
int A[500];

int find(int crnt)
{
    // if (crnt == N) return 0; (없어도 된다)

    int maxLength = 0;
    for (int next = crnt+1; next < N; ++next)
    {
        if (A[next] > A[crnt]) maxLength = max(maxLength, find(next));
    }
    return maxLength + 1; // 자신의 길이를 포함하여 리턴 : +1 한 값
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N;
        for (int i = 0; i < N; ++i) cin >> A[i];

        // 찾을 수열이 어디서부터 시작할 지 모르므로 모두 순회해야 한다.
        int maxLength = 0;
        for (int i = 0; i < N; ++i) maxLength = max(maxLength, find(i));
        cout << maxLength << '\n';
    }
}