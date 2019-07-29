#include <bits/stdc++.h>

using namespace std;

#define MAX 100

vector<int>adjList[MAX + 5];
int inDegree[MAX + 5];
bool visited[MAX + 5];

int main()
{
    //freopen("top-in.txt", "r", stdin);
    //freopen("top-out.txt", "w", stdout);

    int numOfNode, numOfEdge, i, u, v;
    bool found, cycle;
    int visitedCount;
    vector<int>sortedList;

    cout << "Number of nodes: ";
    cin >> numOfNode;
    cout << "Number of edges: ";
    cin >> numOfEdge;

    for (i = 1; i <= numOfEdge; i++) {
        inDegree[i] = 0;
        visited[i] = false;
    }

    cout << "Enter end-points of all edges:\n";
    for (i = 1; i <= numOfEdge; i++) {
        cin >> u >> v;
        adjList[u].push_back(v);
        inDegree[v]++;
    }

    visitedCount = 0;
    cycle = false;
    while (true) {
        if (visitedCount == numOfNode) {
            break;
        }

        found = false;
        for (i = 1; i <= numOfNode; i++) {
            if (inDegree[i] == 0 && !visited[i]) {
                found = true;
                visited[i] = true;
                visitedCount++;

                sortedList.push_back(i);
                for (u = 0; u < adjList[i].size(); u++) {
                    v = adjList[i][u];
                    inDegree[v]--;
                }

                break;
            }
        }

        if (!found && visitedCount != numOfNode) {
            cycle = true;
            break;
        }
    }

    if (cycle) {
        cout << "Cycle is found.\n";
    }
    else {
        for (i = 0; i < sortedList.size(); i++) {
            cout << sortedList[i] << " ";
        }
    }

    return 0;
}


