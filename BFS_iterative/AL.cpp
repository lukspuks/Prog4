#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfsAL(int startNode, int numNodes, const vector<vector<int>>& adjList) {
    vector<bool> visited(numNodes, false);
    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    cout << "BFS (AL) редослед: ";

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << current << " ";

        // Ги изминуваме сите соседи на тековниот јазол
        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}