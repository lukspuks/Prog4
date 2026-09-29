#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfsAM(int start, int num, const vector<vector<int>>& matrix) {
    vector<bool> visited(num, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << current << " ";

        for (int i = 0; i < num; ++i) {
            if (matrix[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}

int main() {
    int num = 5;

    vector<vector<int>> AM = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0}
    };

    bfsAM(0, num, AM);

    return 0;
}