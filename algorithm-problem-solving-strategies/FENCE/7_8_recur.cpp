// 분할 정복과 그리디 알고리즘을 통한 문제해결

#include <iostream>
#include <vector>
using namespace std;

vector<int> hist;

int solve(int left, int right)
{
    // 1. base case: 판자가 하나밖에 없는 경우
    if (left == right) return hist[left];

    // 2. 해답이 어느 한쪽에만 포함된 경우
    int mid = (left + right) / 2;
    int ret = max(solve(left, mid), solve(mid + 1, right));

    // 3. 해답이 가운데 두 판자를 포함하는 경우
    int lo = mid, hi = mid + 1;
    int height = min(hist[lo], hist[hi]);
    ret = max(ret, height * 2); // 가운데 두 판자만 포함하는 경우의 넓이
    while (left < lo || hi < right)
    {
        if (hi < right && (lo == left) || hist[lo - 1] < hist[hi + 1])
        {
            ++hi;
            height = min(height, hist[hi]);
        }
        else
        {
            --lo;
            height = min(height, hist[lo]);
        }
        ret = max(ret, height * (hi - lo + 1));
    }
    return ret;
}

int main()
{
    int C;
    cin >> C;
    for (int i = 0; i < C; ++i)
    {
        int N;
        cin >> N;
        hist.clear();
        for (int j = 0; j < N; ++j)
        {
            int h;
            cin >> h;
            hist.push_back(h);
        }
        cout << solve(0, N - 1) << endl;
    }
    return 0;
}
