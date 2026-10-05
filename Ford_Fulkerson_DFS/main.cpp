#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct MaxFlow {
    struct Edge {
        int to, cap, rev;
    };

    int n;
    vector<vector<Edge>> adj;
    vector<bool> visited;

    MaxFlow(int n) : n(n), adj(n) {}

    void addEdge(int u, int v, int c) {
        int iu = adj[u].size();
        int iv = adj[v].size();
        if (u == v) iv++;
        adj[u].push_back({v, c, iv});
        adj[v].push_back({u, 0, iu});
    }

    int dfs(int u, int t, int flow) {
        if (u == t) return flow;
        visited[u] = true;
        for (Edge &e : adj[u]) {
            if (!visited[e.to] && e.cap > 0) {
                int pushed = dfs(e.to, t, min(flow, e.cap));
                if (pushed > 0) {
                    e.cap -= pushed;
                    adj[e.to][e.rev].cap += pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }

    int solve(int s, int t) {
        if (s == t) return 0;
        int total = 0;
        while (true) {
            visited.assign(n, false);
            int pushed = dfs(s, t, 1e9);
            if (pushed == 0) break;
            total += pushed;
        }
        return total;
    }
};

int main() {
    {
        MaxFlow g(4);
        g.addEdge(0, 1, 8);
        g.addEdge(0, 2, 8);
        g.addEdge(1, 3, 8);
        g.addEdge(2, 1, 1);
        g.addEdge(2, 3, 8);
        cout << "FF Killer max flow: " << g.solve(0, 3) << '\n';
    }

    {
        MaxFlow g(8);
        g.addEdge(0, 1, 1);
        g.addEdge(0, 2, 1);
        g.addEdge(0, 3, 1);
        g.addEdge(1, 6, 1);
        g.addEdge(1, 5, 1);
        g.addEdge(1, 4, 1);
        g.addEdge(2, 5, 1);
        g.addEdge(3, 5, 1);
        g.addEdge(4, 7, 1);
        g.addEdge(5, 7, 1);
        g.addEdge(6, 7, 1);
        cout << "CP4X8531 max flow: " << g.solve(0, 7) << '\n';
    }

    {
        MaxFlow g(8);
        g.addEdge(0, 1, 10);
        g.addEdge(0, 2, 5);
        g.addEdge(0, 3, 15);
        g.addEdge(1, 2, 4);
        g.addEdge(1, 5, 15);
        g.addEdge(1, 4, 9);
        g.addEdge(2, 5, 8);
        g.addEdge(2, 3, 4);
        g.addEdge(3, 6, 16);
        g.addEdge(4, 5, 15);
        g.addEdge(4, 7, 10);
        g.addEdge(5, 6, 15);
        g.addEdge(5, 7, 10);
        g.addEdge(6, 7, 10);
        g.addEdge(6, 2, 6);
        cout << "CS4234 MF Demo max flow: " << g.solve(0, 7) << '\n';
    }

    {
        MaxFlow g(6);
        g.addEdge(0, 1, 1);
        g.addEdge(0, 2, 3);
        g.addEdge(1, 3, 99);
        g.addEdge(1, 4, 99);
        g.addEdge(2, 4, 99);
        g.addEdge(3, 5, 2);
        g.addEdge(4, 5, 2);
        cout << "Matching with Capacity max flow: " << g.solve(0, 5) << '\n';
    }

    return 0;
}