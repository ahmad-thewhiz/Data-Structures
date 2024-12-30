#include <bits/stdc++.h>

using namespace std;

bool isSafe(int x, int y, vector<vector<bool>> &visited, vector<vector<int>> &arr, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n && !visited[x][y] && arr[x][y] == 1);
}

void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans, vector<vector<bool>> &visited, string path) {
    
    // Base case: If the destination is reached
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }

    // Down move
    if (isSafe(x + 1, y, visited, arr, n)) {
        visited[x][y] = true;
        solve(x + 1, y, arr, n, ans, visited, path + 'D');
        visited[x][y] = false;
    }

    // Left move
    if (isSafe(x, y - 1, visited, arr, n)) {
        visited[x][y] = true;
        solve(x, y - 1, arr, n, ans, visited, path + 'L');
        visited[x][y] = false;
    }

    // Right move
    if (isSafe(x, y + 1, visited, arr, n)) {
        visited[x][y] = true;
        solve(x, y + 1, arr, n, ans, visited, path + 'R');
        visited[x][y] = false;
    }

    // Up move
    if (isSafe(x - 1, y, visited, arr, n)) {
        visited[x][y] = true;
        solve(x - 1, y, arr, n, ans, visited, path + 'U');
        visited[x][y] = false;
    }
}

vector<string> searchMaze(vector<vector<int>> &arr, int n) {
    vector<string> ans;
    if (arr[0][0] == 0 || arr[n - 1][n - 1] == 0) {
        return ans;
    }
    
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    string path = "";
    
    solve(0, 0, arr, n, ans, visited, path);
    return ans;
}
