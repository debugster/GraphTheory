#include <bits/stdc++.h>

using namespace std;

#define MAX 100

vector<int>adjList[MAX + 5];
bool visited[MAX + 5];

void BFS(int source)
{
    visited[source] = true;
    cout << source << " ";

    queue<int>Q;
    Q.push(source);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (int i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i];
            if (!visited[v]) {
                visited[v] = true;
                cout << v << " ";
                Q.push(v);
            }
        }
    }
}

int main()
{
    //freopen("bfs-in.txt", "r", stdin);
    //freopen("bfs-out.txt", "w", stdout);

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
    BFS(s);

    return 0;
}
