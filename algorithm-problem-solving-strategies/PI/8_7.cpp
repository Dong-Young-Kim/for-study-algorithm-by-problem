#include <iostream>
#include <string>
using namespace std;

#define INF 1000000000 // INF가 과도하게 큰 경우 오버플로우 발생 가능

string N;

int classify (int a, int b)
// a = 시작 index, b = 끝 index
{
    // 난이도가 낮은 것 부터 차례로 체에 거름

    string M = N.substr(a, b-a+1);

    if (M == string(M.size(), M[0])) return 1; // 연속된 문자인지 판단

    bool progressive = 1;
    int diff = M[1] - M[0];
    for (int i = 0; i < M.size() - 1; ++i)
    {
        if (M[i+1] - M[i] != diff) progressive = 0;
    }
    if (progressive && abs(diff) == 1) return 2; // 1씩 단조 증감 판단

    bool alternating = 1;

    for (int i = 2; i < M.size(); ++i)
    {
        if (M[i] != M[i-2]) alternating = 0; 
    }

    if (alternating) return 4;
    if (progressive) return 5;
    
    return 10;

}


int cache[10002];

int memorize(int begin)
{
    if (begin == N.size()) return 0; // 종료 판단
 
    int& ret = cache[begin];
    
    if (ret != -1) return ret; // 값이 이미 계산되어있는 경우
    
    ret = INF;
    if (begin + 3 <= N.size()) ret = memorize(begin + 3) + classify(begin, begin + 3 - 1);
    if (begin + 4 <= N.size()) ret = min(ret, memorize(begin + 4) + classify(begin, begin + 4 - 1));
    if (begin + 5 <= N.size()) ret = min(ret, memorize(begin + 5) + classify(begin, begin + 5 - 1));

    printf("ret %d\n", ret);
    return ret;

}

int main () 
{
	int T;
    string a;
	cin >> T;
	while (T--) {
        memset(cache, -1, sizeof(cache));
        cin >> N;
        printf("%d\n", memorize(0));

	}
}