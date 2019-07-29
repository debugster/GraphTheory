#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define MAX 100
#define INF 10000000

vector<pii>adjList[MAX + 5];
int adjMatrix[MAX + 5][MAX + 5];

void MSTPrim(int source, int nodes)
{
    // PQ.first => key
    // PQ.second => node number
    priority_queue<pii, vector<pii>, greater<pii> >PQ;
    vector<int>key(nodes + 1, INF);
    vector<int>parent(nodes + 1, -1);
    vector<bool>inMST(nodes + 1, false);
    int totalCost = 0;

    key[source] = 0;
    parent[source] = 0;
    PQ.push(make_pair(0, source));

    while (!PQ.empty()) {
        int u = PQ.top().second;
        PQ.pop();

        inMST[u] = true;

        pii x;
        for (int i = 0; i < adjList[u].size(); i++) {
            x = adjList[u][i];
            int v = x.first;
            int w = x.second;

            if (!inMST[v] && key[v] > w) {
                key[v] = w;
                PQ.push(make_pair(w, v));
                parent[v] = u;
            }
        }
    }

    cout << "Edge List:\n";
    for (int i = 1; i <= nodes; i++) {
        if (i == source) continue;
        cout << i << " - " << parent[i] << "\n";
        totalCost += adjMatrix[i][parent[i]];
    }
    cout << "MST Cost = " << totalCost << "\n";
}

int main()
{
    //freopen("prim-in.txt", "r", stdin);
    //freopen("prim-out.txt", "w", stdout);

    int numOfNode, numOfEdge, i, u, v, w, s;

    cout << "Number of nodes: ";
    cin >> numOfNode;
    cout << "Number of edges: ";
    cin >> numOfEdge;

    cout << "Enter end-points of all edges with cost:\n";
    for (i = 1; i <= numOfEdge; i++) {
        cin >> u >> v >> w;
        adjList[u].push_back(make_pair(v, w));
        adjList[v].push_back(make_pair(u, w));
        adjMatrix[u][v] = adjMatrix[v][u] = w;
    }

    cout << "Enter source: ";
    cin >> s;
    MSTPrim(s, numOfNode);

    return 0;
}


