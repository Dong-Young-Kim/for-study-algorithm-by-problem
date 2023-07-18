#include <iostream>

using namespace std;

int N;
int A[500], cache[501]; // -1 index를 위해서 한 칸 늘림

int find(int crnt)
{
    // 1. 기저사례
    // if (crnt == N) return 0; (없어도 된다)

    // 2. 캐시확인
    int & ret = cache[crnt + 1]; // -1 index로 인해서 한 칸씩 밀어서 cache를 사용
    if (ret != -1) return ret;

    int maxLength = 0;
    for (int next = crnt+1; next < N; ++next)
    {
        // crnt가 -1 이면 error가 발생하므로 crnt == -1이면 가상의 최소값인 -1로 값을 대치한다.
        if (A[next] > (crnt == -1 ? -1 : A[crnt])) maxLength = max(maxLength, find(next));
    }
    return ret = (maxLength + 1); // 자신의 길이를 포함하여 리턴 : +1 한 값
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        memset(cache, -1, sizeof(cache));
        cin >> N;
        for (int i = 0; i < N; ++i) cin >> A[i];

        // 찾을 수열이 어디서부터 시작할 지 모르므로 모두 순회해야 한다.
        // 모두 순회하지 않기 위해서 가상의 -1 번 index를 만듥고 
        int maxLength = 0;
        // for (int i = 0; i < N; ++i) maxLength = max(maxLength, find(i));

        maxLength = find(-1) - 1; // -1 index의 가상의 값도 포함되어 있으므로 최종 결과에서 -1을 빼야한다.
        cout << maxLength << '\n';
    }
}
