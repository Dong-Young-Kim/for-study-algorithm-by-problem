// 구간 최소 쿼리
// Segment Tree를 이용한 구간 최소 쿼리 문제를 해결하는 알고리즘

#include <vector>
using namespace std;

struct RMQ
{
    int n; // 배열 길이
    vector<int> rangeMin; // 각 구간의 최소치
    // rangeMin[node] : node가 표현하는 범위 arr[left, right]의 최소치
    
    RMQ(const vector<int>& arr)
    {
        n = arr.size();
        rangeMin.resize(n * 4); // 배열 필요 크기 (2의 제곱수)
        init(arr, 0, n - 1, 1);
    }
    
    // node 노드가 arr[left, right] 배열을 표현할 때
    // node를 루트로 하는 서브트리를 초기화하고, 이 구간의 최소치를 반환한다.
    int init(const vector<int>& arr, int left, int right, int node)
    {
        if(left == right) return rangeMin[node] = arr[left];
        int mid = (left + right) / 2;
        int leftMin = init(arr, left, mid, node * 2);
        int rightMin = init(arr, mid + 1, right, node * 2 + 1);
        return rangeMin[node] = min(leftMin, rightMin);
    }

    // node 노드가 표현하는 구간 [nodeLeft, nodeRight]와
    // 최소치를 찾기 원하는 구간 [left, right]의 교집합의 최소치를 반환한다.
    // 쿼리 호출 시 query(left, right, 1, 0, n - 1)로 호출한다. [left, right] = 찾고자 하는 구간
    int query(int left, int right, int node, int nodeLeft, int nodeRight)
    {
        // 1. 두 구간이 겹치지 않으면, 아주 큰 값을 반환 (찾는 구간이 포함되지 않음)
        if(right < nodeLeft || nodeRight < left) return INT_MAX;

        // 2. node가 표현하는 범위가 arr[left, right]에 완전히 포함
        if(left <= nodeLeft && nodeRight <= right) return rangeMin[node];

        // 3. 일부 겹치면, 양쪽 구간 재귀 호출하여 최소치 반환
        int mid = (nodeLeft + nodeRight) / 2;
        return min(query(left, right, node * 2, nodeLeft, mid),
                   query(left, right, node * 2 + 1, mid + 1, nodeRight));
    }

    // node가 표현하는 구간 arr[nodeLeft, nodeRight]가 주어질 때,
    // 이 구간과 arr[index]의 값을 newValue로 업데이트하고 노드가 표현하는 구간의 최소치를 반환한다.
    // 업데이트 호출 시 update(index, newValue, 1, 0, n - 1)로 호출한다.
    int update(int index, int newValue, int node, int nodeLeft, int nodeRight)
    {
        // 1. 갱신할 노드를 포함하는 구간이 아니면, 기존 값 반환
        if(index < nodeLeft || index > nodeRight) return rangeMin[node];

        // 2.1 구간과 노드가 동일한 경우 값을 갱신하고 갱신값 반환
        if(nodeLeft == nodeRight) return rangeMin[node] = newValue;

        // 2.2 업데이트 할 값이 구간 내에 있는 경우 재귀호출로 갱신
        int mid = (nodeLeft + nodeRight) / 2;
        return rangeMin[node] = min(
            update(index, newValue, node * 2, nodeLeft, mid),
            update(index, newValue, node * 2 + 1, mid + 1, nodeRight));
    }
};