#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int u, v;
};

void dfsHelperEL(int current, const vector<Edge>& edges, vector<bool>& visited) {
    visited[current] = true;
    cout << current << " ";

    for (const auto& edge : edges) {
        if (edge.u == current && !visited[edge.v]) {
            dfsHelperEL(edge.v, edges, visited);
        } else if (edge.v == current && !visited[edge.u]) {
            dfsHelperEL(edge.u, edges, visited);
        }
    }
}

void dfsEL(int start, int num, const vector<Edge>& edges) {
    vector<bool> visited(num, false);
    dfsHelperEL(start, edges, visited);
    cout << endl;
}

int main() {
    int num = 5;

    vector<Edge> EL = {
        {0, 1}, {0, 2}, {1, 3}, {1, 4}
    };

    dfsEL(0, num, EL);

    return 0;
}