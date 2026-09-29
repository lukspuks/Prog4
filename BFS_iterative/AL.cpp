#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfsAL(int start, int num, const vector<vector<int>>& list) {
    vector<bool> visited(num, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << current << " ";

        for (int neighbor : list[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    int num = 5;

    vector<vector<int>> AL(num);
    AL[0] = {1, 2};
    AL[1] = {0, 3, 4};
    AL[2] = {0};
    AL[3] = {1};
    AL[4] = {1};

    bfsAL(0, num, AL);

    return 0;
}