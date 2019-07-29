#include <bits/stdc++.h>

using namespace std;

#define MAX 100

struct EDGE
{
    int u;
    int v;
    int cost;

    bool operator<(EDGE &a)
    {
        return cost < a.cost;
    }
};

struct DisjointSet
{
    vector<int>parent;

    void setTree(int nodes)
    {
        parent.assign(nodes + 1, 0);

        for (int i = 1; i <= nodes; i++) {
            parent[i] = i;
        }
    }

    int findSet(int i) /// find the set representative of node 'i'
    {
        if (parent[i] != i) {
            parent[i] = findSet(parent[i]);
        }
        return parent[i];
    }

    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }

    void makeUnion(int i, int j)
    {
        if (!isSameSet(i, j)) {

            int x = findSet(i);
            int y = findSet(j);

            parent[y] = x;
        }
    }
};

vector<EDGE>allEdge;
vector<EDGE>ansEdge;

void MSTKruskal(int nodes)
{
    set<int>connected;
    DisjointSet tree;
    int totalCost = 0;

    tree.setTree(nodes);

    EDGE e;
    for (int i = 0; i < allEdge.size(); i++) {
        e = allEdge[i];
        int u = e.u;
        int v = e.v;
        int w = e.cost;

        if (!tree.isSameSet(u, v)) {
            tree.makeUnion(u, v);
            totalCost += w;
            ansEdge.push_back(e);
            connected.insert(u);
            connected.insert(v);
        }

        if (connected.size() == nodes) {
            break;
        }
    }

    cout << "Edge List:\n";
    for (int i = 0; i < ansEdge.size(); i++) {
        cout << ansEdge[i].u << " - " << ansEdge[i].v << "\n";
    }
    cout << "MST Cost = " << totalCost << "\n";
}

int main()
{
    //freopen("kruskal-in.txt", "r", stdin);
    //freopen("kruskal-out.txt", "w", stdout);

    int numOfNode, numOfEdge, i, u, v, w;

    cout << "Number of nodes: ";
    cin >> numOfNode;
    cout << "Number of edges: ";
    cin >> numOfEdge;

    cout << "Enter end-points of all edges with cost:\n";
    for (i = 1; i <= numOfEdge; i++) {
        cin >> u >> v >> w;
        allEdge.push_back({u, v, w});
    }

    sort(allEdge.begin(), allEdge.end());

    MSTKruskal(numOfNode);

    return 0;
}


