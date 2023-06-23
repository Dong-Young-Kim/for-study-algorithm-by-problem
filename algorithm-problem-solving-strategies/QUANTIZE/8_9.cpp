#include <iostream>
#include <string>
using namespace std;

#define INF 1000000000 // INF가 과도하게 큰 경우 오버플로우 발생 가능

int L[102];
int N, S;


int minError (int begin, int end)
// 주어진 그룹의 최소 Error를 반환하는 함수
{
    
}


int cache[101][11];
// cache[i][j] -> i번째 숫자부터의 숫자들을 j개로 묶었을 때의 최솟값

int quantize(int begin, int group)
// begin 이후의 숫자들을 group개의 묶음으로 묶을 떄 최소 오류 제곱 합을 반환하는 함수
{
    if (begin == N) return 0;   // 종료 판단
    if (group == 0) return INF; // 남은 group이 없는 경우

    int& ret = cache[begin][group];
    
    if (ret != -1) return ret; // 값이 이미 계산되어있는 경우
    
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

        printf("%d\n", quantize(0, S));

	}
}