#include <iostream>
#include <vector>

using namespace std;

struct BiDisjointSet
{
    vector<int> parent, rank, anti, arank;

        // 모든 원소가 각각의 집합에 속하도록 초기화 
    BiDisjointSet(int n)
        : parent(n), rank(n, 1)
    {
        for(int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    void ack(int u, int v)
    {

    }

    void dis(int u, int v)
    {

    }

};




int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N, M; // N = 회원 수, M = 정보 수
        cin >> N >> M;
        for (int i = 0; i < M; ++i)
        {
            string info;
            int a, b;
            cin >> info >> a >> b;



        }
    }
}