#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int u, v;
};

void bfsEL(int start, int num, const vector<Edge>& edges) {
    vector<bool> visited(num, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << current << " ";

        for (const auto& edge : edges) {
            if (edge.u == current && !visited[edge.v]) {
                visited[edge.v] = true;
                q.push(edge.v);
            } else if (edge.v == current && !visited[edge.u]) {
                visited[edge.u] = true;
                q.push(edge.u);
            }
        }
    }
    cout << endl;
}

int main() {
    int num = 5;

    vector<Edge> EL = {
        {0, 1}, {0, 2}, {1, 3}, {1, 4}
    };

    bfsEL(0, num, EL);

    return 0;
}