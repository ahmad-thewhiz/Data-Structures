#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    bool isSafe(int row, int col, unordered_map<int, bool>& rows, unordered_map<int, bool>& upperLeft, unordered_map<int, bool>& lowerLeft, int n) {
        if (rows[row] || upperLeft[(n - 1) + col - row] || lowerLeft[row + col])
            return false;
        return true;
    }

    void addSolution(vector<string>& board, vector<vector<string>>& res, int n) {
        res.push_back(board);
    }

    void solve(int col, unordered_map<int, bool>& rows, unordered_map<int, bool>& upperLeft, unordered_map<int, bool>& lowerLeft, vector<string>& board, vector<vector<string>>& res, int n) {
        if (col == n) {
            addSolution(board, res, n);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, rows, upperLeft, lowerLeft, n)) {
                // Place the queen
                rows[row] = true;
                upperLeft[(n - 1) + col - row] = true;
                lowerLeft[row + col] = true;
                board[row][col] = 'Q';

                // Recur to place next queen
                solve(col + 1, rows, upperLeft, lowerLeft, board, res, n);

                // Backtrack
                board[row][col] = '.';
                rows[row] = false;
                upperLeft[(n - 1) + col - row] = false;
                lowerLeft[row + col] = false;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        unordered_map<int, bool> rows;
        unordered_map<int, bool> upperLeft;
        unordered_map<int, bool> lowerLeft;

        solve(0, rows, upperLeft, lowerLeft, board, res, n);
        return res;
    }
};
