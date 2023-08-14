#include <iostream>
#include <vector>
using namespace std;


struct Node
{
    Node* parent;
    vector<Node*> child;
    vector<int> idxAdjcent; // for input
    int sizeSubtree;
};
vector<Node> nodes(100001); // adjecent list

int N, R, Q; // node, root, query

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

void countSubtree(Node* curNode)
{
    curNode->sizeSubtree = 1;

    for (Node* child : curNode->child)
    {
        countSubtree(child);
        curNode->sizeSubtree += child->sizeSubtree;   
    }
}

int main()
{
    cin >> N >> R >> Q;
    for (int i = 0; i < N-1; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;

        // 모든 간선 정보를 adejecent list 형식으로 저장한다.
        nodes[v1].idxAdjcent.push_back(v2);
        nodes[v2].idxAdjcent.push_back(v1);
    }
    
    nodes[R].parent = nullptr;
    makeTree(R, -1); // root node, parent node

    countSubtree(&nodes[R]);
    
    for (int i = 0; i < Q; ++i)
    {
        int query;
        cin >> query;
        cout << nodes[query].sizeSubtree << '\n';
    }

}