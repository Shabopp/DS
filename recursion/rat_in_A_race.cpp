#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>>& visited, vector<vector<int>>& m) {
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1) {
        return true;
    }
    else {
        return false;
    }
}

void solve(vector<vector<int>>& m, int n, vector<string>& ans, int x, int y, vector<vector<int>>& visited, string path) {
    // base case
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;
    // DOWN
    int newx = x + 1;
    int newy = y;
    if (isSafe(newx, newy, n, visited, m)) {
        path.push_back('D');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }
    // UP
    newx = x - 1;
    newy = y;
    if (isSafe(newx, newy, n, visited, m)) {
        path.push_back('U');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }
    // LEFT
    newx = x;
    newy = y - 1;
    if (isSafe(newx, newy, n, visited, m)) {
        path.push_back('L');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }
    // RIGHT
    newx = x;
    newy = y + 1;
    if (isSafe(newx, newy, n, visited, m)) {
        path.push_back('R');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }
    visited[x][y] = 0;
}

int main() {
    int n = 4; // Size of the matrix (you can change this to your desired size)

    // Define the maze matrix with 1s and 0s
    vector<vector<int>> m = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> ans;
    // if the starting cell is 0 (blockage), there's no path
    if (m[0][0] == 0) {
        // Output an empty path
        cout << "No paths possible." << endl;
        return 0;
    }
    int srcx = 0;
    int srcy = 0;
    vector<vector<int>> visited = m;
    // Initialize all cells as unvisited (0)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }
    string path;
    solve(m, n, ans, srcx, srcy, visited, path);
    sort(ans.begin(), ans.end());

    // Output the paths
    for (const string& p : ans) {
        cout << p << " ";
    }

    return 0;
}
