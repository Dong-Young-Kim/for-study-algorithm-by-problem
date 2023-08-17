// LIS with nlogn

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
        cache.push_back(0); // 첫 값 추가를 위한 최솟값 입력

        cin >> N;
        for (int i = 0; i < N; ++i) 
        {
            cin >> num;
            insert(num);
        }
        
        cout << cache.size() - 1; // 첫 값 추가를 위한 최솟값 제거
}

// 생각해보니까 굳이 배열 전부를 미리 안 받아놓아도
// cin 으로 입력 받으면서 계산을 할 수 있겠다.
// 이러면 공간 복잡도가 확 줄겠지..?