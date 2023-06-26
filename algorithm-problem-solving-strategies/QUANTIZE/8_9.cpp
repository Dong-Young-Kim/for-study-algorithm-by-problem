#include <iostream>
using namespace std;

#define INF 1000000000 // INF가 과도하게 큰 경우 오버플로우 발생 가능

int L[101];
int N, S;
int qSum[101], qSqSum[101];

// cache[i][j] -> i번째 숫자부터의 숫자들을 j개로 묶었을 때의 최솟값
int cache[101][11];

void preCalc()
// 시간 단축을 위한 사전 계산
{
    sort(L, L + N); // 입력된 배열 정렬 (오름차순)

    qSum[0] = L[0];
    qSqSum[0] = L[0] * L[0];

    for (int i = 1; i < N; i++)
    {
        qSum[i] = qSum[i - 1] + L[i];
        qSqSum[i] = qSqSum[i - 1] + (L[i] * L[i]);
    }
}

int minError (int begin, int end)
// 주어진 그룹의 대표값(양자화 값)을 결정하고, 최소 Error를 반환하는 함수
{
    int groupSize = end - begin + 1;
    // begin이 1인 경우는 예외처리
    int localSum = begin == 0 ? qSum[end] : qSum[end] - qSum[begin - 1];
    int localSqSum = begin == 0 ? qSqSum[end] : qSqSum[end] - qSqSum[begin - 1];

    // int ave = (int)(localSum / groupSize);       // 이렇게 하면 내림 처리된다
    // int ave = (int)(localSum / groupSize + 0.5); // 이렇게 해도 내림 처리된다
    int ave = (int)((double)localSum / groupSize + 0.5);

    printf("minErr: %d\n", (ave * ave * groupSize) - (2 * ave * localSum) + localSqSum);
    return (ave * ave * groupSize) - (2 * ave * localSum) + localSqSum;

}

int quantize(int begin, int group)
// begin 이후의 숫자들을 group개의 묶음으로 묶을 떄 최소 오류 제곱 합을 반환하는 함수
{
    if (begin == N) return 0;   // 종료 판단
    if (group == 0) return INF; // 남은 group이 없는 경우

    int& ret = cache[begin][group];
    
    if (ret != -1) return ret; // 값이 이미 계산되어있는 경우
    
    ret = INF; // *** 빼먹지 않기 ***
    for (int i = 1; i <= N - begin; ++i)
    // 한 group의 크기가 1일때 ~ 최대크기 (N-begin) 일때까지
    {
        ret = min(ret, minError(begin, begin+i-1) + quantize(begin+i, group-1));
    }
    return ret;
}

int main () 
{
	int T;
	cin >> T;
	while (T--) {
        memset(cache, -1, sizeof(cache));
        cin >> N >> S;
        for (int i = 0; i < N; ++i) cin >> L[i];
        preCalc();
        printf("%d\n", quantize(0, S));

        for (int j = 0; j < 10; j++)
        {
            for (int i = 0; i < N; ++i)
            {
                printf("%d ", cache[i][j]);
            }
            printf("\n");
        }
	}
}
