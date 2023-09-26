#include <iostream>
#include <string>

#define maxD 100
#define maxO 100
#define maxK 1000000000

using namespace std;

int skip;
int bino[maxD+maxO+1][maxD+maxO+1];
// void calcBino();

// 1. 완전탐색
void generateAll(int d, int o, string s)
{
    // 1. 기저사례
    if(d == 0 && o == 0)
    {
        cout << s << "\n";
        return;
    }
    if(d > 0) generateAll(d-1, o, s + "-");
    if(o > 0) generateAll(d, o-1, s + "o");
}

// 2. 출력 skip
void generateAllAndSkipPrint(int d, int o, string s)
{
    if (skip < 0) return; // k 신호를 찾은 경우 더이상 탐색하지 않도록
    
    // 1. 기저사례
    if(d == 0 && o == 0)
    {
        if(skip == 0) cout << s << "\n";
        --skip;
        return;
    }
    if(d > 0) generateAllAndSkipPrint(d-1, o, s + "-");
    if(o > 0) generateAllAndSkipPrint(d, o-1, s + "o");
}

// 3. 이항계수로 skip
void generateAndSkipByBino(int d, int o, string s)
{
    if (skip < 0) return; // k 신호를 찾은 경우 더이상 탐색하지 않도록
    
    // 1. 기저사례
    if(d == 0 && o == 0)
    {
        if(skip == 0) cout << s << "\n";
        --skip;
        return;
    }

    // 현재 이 재귀함수가 탐색하는 구간을 전부 돌아도 skip이 남는 경우
    if (bino[d+o][d] < skip)
    {
        skip -= bino[d+o][d];
        return;
    }

    if(d > 0) generateAndSkipByBino(d-1, o, s + "-");
    if(o > 0) generateAndSkipByBino(d, o-1, s + "o");
}

// 4. k번째를 반환하는 함수
// d, o가 주어진 신호에서 skip개의 신호를 건너뛰고 나오는 신호
string calcKth(int d, int o, int skip)
{
    if (d == 0) return string(o, 'o'); // d가 0이되면 나머지는 모두 "o"

    // o가 0 밑으로 떨어지는 경우는 발생하지 않는다.
    if (skip < bino[d+o-1][d-1]) return "-" + calcKth(d-1, o, skip);
    else return "o" + calcKth(d, o-1, skip - bino[d+o-1][d-1]);
}

// etc. 이항계수 계산
void calcBino()
{
    for (int i = 0; i <= maxD+maxO; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (j == 0 || i == j) bino[i][j] = 1;
            else 
            {
                // 오버플로우 방지 : k보다 크므로 동일하게 skip 된다
                bino[i][j] = min(maxK+1, bino[i-1][j-1] + bino[i-1][j]);
            }
        }
    }
}

int main()
{
    int d, o, k;

    calcBino();

    while(1)
    {
        cin >> d >> o >> k;
        skip = k - 1; // k-1개의 신호를 skip해야 찾는 신호가 나온다
        // generateAndSkipByBino(d, o, "");
        cout << calcKth(d, o, skip) << "\n";
    }
    return 0;
}