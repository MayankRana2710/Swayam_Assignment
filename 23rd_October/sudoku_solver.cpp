#include <bits/stdc++.h>
using namespace std;

// Check if placing 'ch' in board[row][col] is valid
bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
    for (int i = 0; i < 9; i++) {
        // Check row
        if (board[row][i] == ch) return false;
        // Check column
        if (board[i][col] == ch) return false;
        // Check 3x3 subgrid
        int subRow = 3 * (row / 3) + i / 3;
        int subCol = 3 * (col / 3) + i % 3;
        if (board[subRow][subCol] == ch) return false;
    }
    return true;
}

// Recursive backtracking function
bool solve(vector<vector<char>>& board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == '.' || board[row][col] == '0') {
                for (char ch = '1'; ch <= '9'; ch++) {
                    if (isValid(board, row, col, ch)) {
                        board[row][col] = ch;

                        if (solve(board))
                            return true;  // Solved!

                        // Backtrack
                        board[row][col] = '.';
                    }
                }
                return false;  // No valid number found
            }
        }
    }
    return true;  // All cells filled successfully
}

void printBoard(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<char>> board(9, vector<char>(9));
    cout << "Enter Sudoku board (use 0 or . for empty cells):\n";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char c;
            cin >> c;
            board[i][j] = c;
        }
    }

    if (solve(board)) {
        cout << "\nSolved Sudoku:\n";
        printBoard(board);
    } else {
        cout << "No solution exists!\n";
    }

    return 0;
}
