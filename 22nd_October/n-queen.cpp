#include <iostream>
#include <vector>
using namespace std;

// Function to print the chessboard
void printSolution(const vector<vector<int>>& board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
    cout << endl;
}

// Check if a queen can be placed safely at board[row][col]
bool isSafe(const vector<vector<int>>& board, int row, int col, int N) {
    // Check column on upper rows
    for (int i = 0; i < row; i++)
        if (board[i][col]) return false;

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j]) return false;

    return true;
}

// Recursive utility function to solve N Queen problem
bool solveNQueenUtil(vector<vector<int>>& board, int row, int N) {
    if (row == N) {
        // All queens placed successfully
        printSolution(board, N);
        return true;
    }

    bool res = false;
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1; // Place queen
            res = solveNQueenUtil(board, row + 1, N) || res;
            board[row][col] = 0; // Backtrack
        }
    }
    return res;
}

// Main function to solve N Queens problem
void solveNQueen(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (!solveNQueenUtil(board, 0, N)) {
        cout << "No solution exists for N = " << N << endl;
    }
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    solveNQueen(N);
    return 0;
}
