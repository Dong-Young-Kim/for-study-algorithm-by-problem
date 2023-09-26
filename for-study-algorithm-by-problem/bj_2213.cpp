#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int weight; // 정점의 가중치
    Node* parent;
    vector<Node*> child;
    vector<int> idxAdjcent; // for input
    int sizeSubtree;
};
vector<Node> nodes; // adjecent list

void makeTree(int idxCurrentNode, int idxParent)
{
    Node& curNode = nodes[idxCurrentNode];

    int adjSize = curNode.idxAdjcent.size();
    for (int i = 0; i < adjSize; ++i)
    {
        Node& adjNode = nodes[curNode.idxAdjcent[i]];
        if (curNode.idxAdjcent[i] != idxParent)
        {
            // add Node to currentNode’s child
            curNode.child.push_back(&adjNode);

            // set Node’s parent to currentNode
            adjNode.parent = &curNode;

            makeTree(curNode.idxAdjcent[i], idxCurrentNode);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    nodes.resize(N + 1);

    // weight 저장
    for (int i = 1; i <= N; ++i)
    {
        cin >> nodes[i].weight;
    }

    // 간선 정보 저장 (트리의 간선 수 = 정점 수 - 1)
    for (int i = 1; i < N; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;

        // 모든 간선 정보를 adejecent list 형식으로 저장한다.
        nodes[v1].idxAdjcent.push_back(v2);
        nodes[v2].idxAdjcent.push_back(v1);
    }

    // 우선 tree의 root node가 주어지지 않았다.
    // root node를 임의로 설정해야 하는가?
    
    // nodes[R].parent = nullptr;
    // makeTree(R, -1); // root node, parent node


}