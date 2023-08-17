// 가장 긴 증가하는 부분 수열 3

// 가장 긴 증가하는 부분 수열 2 (12015) 에서 변형
// 음수 부분 처리 변형

#include <iostream>
#include <vector>

using namespace std;

int N, num;
vector<int> A;
vector<int> cache;


void insert(int num)
{
    A.push_back(num);

    // 증가하는 수열이라면
    if (cache.back() < num) cache.push_back(num);
    else
    {
        // lower_bound 는 찾으려는 값보다 크거나 같은 첫번째 위치를 반환
        vector<int>::iterator it = lower_bound(cache.begin(), cache.end(), num);
        *it = num; // 그 위치에 새로운 값으로 치환
    }

}

int main()
{
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        cache.push_back(-1000000001); // 첫 값 추가를 위한 최솟값 입력 (음수 처리되도록)

        cin >> N;
        for (int i = 0; i < N; ++i) 
        {
            cin >> num;
            insert(num);
        }
        
        cout << cache.size() - 1; // 첫 값 추가를 위한 최솟값 제거
}

/*
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다.
둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (-1,000,000,000 ≤ Ai ≤ 1,000,000,000)
*/