#include <iostream>
#include <vector>

using namespace std;

void dfsHelperAL(int current, const vector<vector<int>>& list, vector<bool>& visited) {
    visited[current] = true;
    cout << current << " ";

    for (int neighbor : list[current]) {
        if (!visited[neighbor]) {
            dfsHelperAL(neighbor, list, visited);
        }
    }
}

void dfsAL(int start, int num, const vector<vector<int>>& list) {
    vector<bool> visited(num, false);
    dfsHelperAL(start, list, visited);
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

    dfsAL(0, num, AL);

    return 0;
}