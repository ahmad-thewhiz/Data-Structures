class Solution {
private:
    bool isSafe(int row, int col, const vector<vector<int>>& board, int n) {
        int x = row, y = col;

        // Check the same row on the left
        while (y > 0) {
            y--;
            if (board[x][y] == 1)
                return false;
        }

        // Check upper-left diagonal
        x = row, y = col;
        while (x > 0 && y > 0) {
            x--;
            y--;
            if (board[x][y] == 1)
                return false;
        }

        // Check lower-left diagonal
        x = row, y = col;
        while (x < n - 1 && y > 0) {
            x++;
            y--;
            if (board[x][y] == 1)
                return false;
        }

        return true;
    }


    void addSolution(const vector<vector<int>>& board, vector<vector<string>>& res, int n) {
        vector<string> temp;
        for (int i = 0; i < n; i++) {
            string row;
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 0)
                    row.push_back('.');
                else
                    row.push_back('Q');
            }
            temp.push_back(row);
        }
        res.push_back(temp);
    }

    void solve(int col, vector<vector<string>>& res, vector<vector<int>>& board, int n) {
        if (col == n) {
            addSolution(board, res, n);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 1;   // Place the queen
                solve(col + 1, res, board, n); // Recurse for the next column
                board[row][col] = 0;   // Backtrack
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<vector<int>> board(n, vector<int>(n, 0));

        solve(0, res, board, n);

        return res;
    }
};
