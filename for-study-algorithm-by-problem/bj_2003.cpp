// 투 포인터를 이용한 부분합 문제

#include <iostream>

using namespace std;

int N, M, A[10000];

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> A[i];

    int num = 0, sum = 0, s = 0, e = 0;

    while(e <= N)
    {
        if (sum == M) ++num;
        if (sum >= M) sum -= A[s++];
        else sum += A[e++];
    }
    printf("%d", num);
}


/*
투 포인터 알고리즘
s와 e를 이용
항상 s <= e를 만족
부분합은 s부터 e-1 까지로 표현

e <= N일떄 까지 아래를 반복
    1. sum >=M (혹은 e==N이면: 없어도 될듯..) sum에서 A[s]를 빼고 나서 s를 증가(s++)하고 
    2. 그렇지 않다면 e를 증가(e++)시키고 sum에 A[e]를 더한다 
    3. sum==M이면 count
    
*/

// 주의:
// 모든 배열이 양수인 경우에만 정합한다.