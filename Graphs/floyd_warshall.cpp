#include <bits/stdc++.h>

using namespace std;

void shortest_distance(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Initialize the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 1e9; // Representing infinity
            }
            if (i == j) {
                matrix[i][j] = 0;
            }
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][k] != 1e9 && matrix[k][j] != 1e9) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }

    // Check for negative cycles
    for (int i = 0; i < n; i++) {
        if (matrix[i][i] < 0) {
            cout << "Negative Cycle Found" << endl;
            return; // Exit if a negative cycle is detected
        }
    }

    // Convert 'infinity' back to -1 for unreachable nodes
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1e9) {
                matrix[i][j] = -1;
            }
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {0, 3, -1, 5},
        {2, 0, -1, 4},
        {-1, 1, 0, -1},
        {-1, -1, 2, 0}
    };

    shortest_distance(matrix);

    cout << "Shortest distances matrix:" << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            if (val == -1) {
                cout << "INF ";
            } else {
                cout << val << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
