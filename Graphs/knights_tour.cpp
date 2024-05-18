#include <iostream>
#include <vector>
using namespace std;

#define N 8  // Define the size of the chessboard

// Function to check if the next move is within the board and the cell is not yet visited
bool isValid(int i, int j, const vector<vector<int>>& matrix) {
    return (i >= 0 && i < N && j >= 0 && j < N && matrix[i][j] == -1);
}

// Recursive function to solve the Knight's Tour problem
bool knightTour(vector<vector<int>>& matrix, int i, int j, int step_count, const vector<int>& x_move, const vector<int>& y_move) {
    // If all cells are visited, return true
    if (step_count == N * N) {
        return true;
    }
    
    // Try all possible moves from the current cell
    for (int k = 0; k < 8; ++k) {
        int next_i = i + x_move[k];
        int next_j = j + y_move[k];
        
        // Check if the next move is valid
        if (isValid(next_i, next_j, matrix)) {
            matrix[next_i][next_j] = step_count; // Mark the cell as visited
            // Recursively try the next move
            if (knightTour(matrix, next_i, next_j, step_count + 1, x_move, y_move)) {
                return true;
            } else {
                matrix[next_i][next_j] = -1; // Backtrack if the move does not lead to a solution
            }
        }
    }
    return false; // Return false if no valid moves are found
}

// Function to initiate the Knight's Tour
bool startKnightTour() {
    // Initialize the chessboard with -1 (unvisited cells)
    vector<vector<int>> matrix(N, vector<int>(N, -1));

    // Possible moves for the knight
    vector<int> x_move = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> y_move = {1, 2, 2, 1, -1, -2, -2, -1};

    matrix[0][0] = 0; // Start position of the knight

    // Start the Knight's Tour from the first cell
    if (knightTour(matrix, 0, 0, 1, x_move, y_move)) {
        // Print the solution matrix
        for (const auto& row : matrix) {
            for (int cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
        return true;
    } else {
        cout << "Solution does not exist." << endl;
        return false;
    }
}

// Main function to start the program
int main() {
    startKnightTour(); // Initiate the Knight's Tour
    return 0;
}
