// 트리를 이용한 disjointset의 구현

#include <vector>
using namespace std;

struct NaiveDisjointSet {
    vector<int> parent;
    
    // 모든 원소가 각각의 집합에 속하도록 초기화 
    NaiveDisjointSet(int n)
        : parent(n)
    {
        for(int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    // u가 속한 집합을 find (root를 반환) 
    int find(int u){
        if(u == parent[u]) return u;
        return find(parent[u]);
    }

    // u, v가 속한 집합을 union
    int merge(int u, int v)
    {
        u = find(u);
        v = find(v);

        if(u == v) return;
        parent[u] = v; // v에 집합 u을 merge
    }
};

struct DisjointSet {
    vector<int> parent, rank;
    
    // 모든 원소가 각각의 집합에 속하도록 초기화 
    DisjointSet(int n)
        : parent(n), rank(n, 1)
    {
        for(int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    // u가 속한 집합을 find (root를 반환) 
    int find(int u){
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]); // path compression optimization
    }

    // u, v가 속한 집합을 union
    int merge(int u, int v)
    {
        u = find(u);
        v = find(v);

        if(u == v) return;
        
        // union by rank
        if(rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        if (rank[u] == rank[v]) ++rank[v];
    }
};
