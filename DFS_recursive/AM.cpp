#include <iostream>
#include <vector>

using namespace std;

void dfsHelperAM(int current, int num, const vector<vector<int>>& matrix, vector<bool>& visited) {
    visited[current] = true;
    cout << current << " ";

    for (int i = 0; i < num; ++i) {
        if (matrix[current][i] == 1 && !visited[i]) {
            dfsHelperAM(i, num, matrix, visited);
        }
    }
}

void dfsAM(int start, int num, const vector<vector<int>>& matrix) {
    vector<bool> visited(num, false);
    dfsHelperAM(start, num, matrix, visited);
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

    dfsAM(0, num, AM);

    return 0;
}