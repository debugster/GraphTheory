#include <bits/stdc++.h>

using namespace std;

#define MAX 100

vector<int>adjList[MAX + 5];
bool visited[MAX + 5];

void DFS(int source)
{
    visited[source] = true;
    cout << source << " ";

    for (int i = 0; i < adjList[source].size(); i++) {
        int v = adjList[source][i];
        if (!visited[v]) {
            DFS(v);
        }
    }
}

int main()
{
    //freopen("dfs-in.txt", "r", stdin);
    //freopen("dfs-out.txt", "w", stdout);

    int numOfNode, numOfEdge, i, u, v, s;

    cout << "Number of nodes: ";
    cin >> numOfNode;
    cout << "Number of edges: ";
    cin >> numOfEdge;

    cout << "Enter end-points of all edges:\n";
    for (i = 1; i <= numOfEdge; i++) {
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    cout << "Enter source node: ";
    cin >> s;
    DFS(s);

    return 0;
}


