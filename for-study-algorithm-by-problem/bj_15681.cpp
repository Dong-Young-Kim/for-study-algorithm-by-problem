#include <iostream>
#include <vector>
using namespace std;


struct Node
{
    int parent;
    vector<int> child;
    vector<int> adjcent;
};
vector<Node> nodes(100001); // adjecent list
int N, R, Q; // node, root, query

void makeTree(int idxCurrentNode, int idxParent)
{
    Node& curNode = nodes[idxCurrentNode];

    int adjSize = curNode.adjcent.size();
    for (int i = 0; i < adjSize; ++i)
    {
        int idxAdjNode = curNode.adjcent[i];
        if (idxAdjNode != idxParent)
        {
            // add Node to currentNode’s child
            curNode.child.push_back(idxAdjNode);

            // set Node’s parent to currentNode
            nodes[idxAdjNode].parent = idxCurrentNode;

            makeTree(idxAdjNode, idxCurrentNode);
        }
    }
}

void countSubtree(int idxCurrentNode)
{
    Node& curNode = nodes[idxCurrentNode];

    int childSize = curNode.child.size();
    for (int i = 0; i < childSize; ++i)
    {
        int idxChildNode = curNode.child[i];
        countSubtree(idxChildNode);
    }
}

int main()
{
    cin >> N >> R >> Q;
    for (int i = 0; i < N; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;

        // 모든 간선 정보를 adejecent list 형식으로 저장한다.
        nodes[v1].adjcent.push_back(v2);
        nodes[v2].adjcent.push_back(v1);
    }
    
    nodes[R].parent = -1;
    makeTree(R, -1); // root node, parent node
    
    for (int i = 0; i < Q; ++i)
    {
        int query;
        cin >> query;
        cout << nodes[query].child.size() + 1 << '\n';
    }


}