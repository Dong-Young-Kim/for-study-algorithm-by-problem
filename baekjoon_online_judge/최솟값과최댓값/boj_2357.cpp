// boj_2357 : 최솟값과 최댓값

// 입력된 수 배열에서 최댓값과 최솟값을 반복적으로 출력하는 문제

// algorithm-problem-solving-strategies의 RMQ를 사용한다.

#include <iostream>
#include <vector>
#define INT_MAX 2147483647
using namespace std;

struct RMQ
{
    int n;
    vector<int> rangeMin;
    RMQ(const vector<int>& arr)
    {
        n = arr.size();
        rangeMin.resize(n * 4);
        init(arr, 0, n - 1, 1);
    }
    int init(const vector<int>& arr, int left, int right, int node)
    {
        if(left == right) return rangeMin[node] = arr[left];
        int mid = (left + right) / 2;
        int leftMin = init(arr, left, mid, node * 2);
        int rightMin = init(arr, mid + 1, right, node * 2 + 1);
        return rangeMin[node] = min(leftMin, rightMin);
    }
    int query(int left, int right, int node, int nodeLeft, int nodeRight)
    {
        if(right < nodeLeft || nodeRight < left) return INT_MAX;
        if(left <= nodeLeft && nodeRight <= right) return rangeMin[node];
        int mid = (nodeLeft + nodeRight) / 2;
        return min(query(left, right, node * 2, nodeLeft, mid),
                   query(left, right, node * 2 + 1, mid + 1, nodeRight));
    }
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<int> arr(N);
    for(int i = 0; i < N; ++i) cin >> arr[i];
    RMQ minTree(arr);
    for(int i = 0; i < N; ++i) arr[i] = -arr[i];
    RMQ maxTree(arr);
    for(int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        cout << minTree.query(a-1, b-1, 1, 0, N-1) << ' ' << 
            - maxTree.query(a-1, b-1, 1, 0, N-1) << '\n';
    }
}

// RMaxQ는 RMQ를 재활용 한다. 음수로 변환 후 입력하고 출력 결과에 음수를 붙여서 출력한다.