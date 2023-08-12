#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> A;
vector<int> B;

// 메모리 초과
// vector<int> Asum(2000000001, 0);
// vector<int> Bsum(2000000001, 0);
// const int SUMOFFSET = 1000000000;

vector<int> Asum;
vector<int> Bsum;

int main()
{
    int T, n, m;
    cin >> T;

    cin >> n;
    A.resize(n);
    for (int i = 0; i < n; ++i) cin >> A[i];

    cin >> m;
    B.resize(m);
    for (int i = 0; i < m; ++i) cin >> B[i];
    
    // 배열 A에서 발생하는 모든 부분합을 계산한다
    for (int i = 0; i < n; ++i)
    {
        int sum = 0;
        for (int j = i; j < n; ++j)
        {
            sum += A[j];
            Asum.push_back(sum);
        }
    }

    // 배열 B에서 발생하는 모든 부분합을 계산한다.
    for (int i = 0; i < m; ++i)
    {
        int sum = 0;
        for (int j = i; j < m; ++j)
        {
            sum += B[j];
            Bsum.push_back(sum);
        }
    }

    sort(Bsum.begin(), Bsum.end());

    // A의 부분합과 B의 부분합을 더해서 T가 되는 경우의 수를 계산한다.
    long long ret = 0;
    for (int elementAsum : Asum)
    {
        ret += upper_bound(Bsum.begin(), Bsum.end(), T - elementAsum) 
            - lower_bound(Bsum.begin(), Bsum.end(), T - elementAsum);
    }

    cout << ret << endl;
}

// 배열 A에서 발생하는 모든 부분합을 계산한다.
// 배열 B에서 발생하는 모든 부분합을 계산한다.

// A의 부분합 중 B의 부분합과 더해서 T가 되는 경우의 수를 계산한다.


/*
A의 부분합이 발생되는 경우의 수는 몇 개인가

배열의 크기 최대 1,000개
원소 하나의 크기 +- 1,000,000 
최대 1,000,000,000
vector<int> Asum = (0, 2,000,000,001);
*/