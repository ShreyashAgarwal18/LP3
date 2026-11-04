#include <iostream>
using namespace std;

int board[8][8];

bool isSafe(int row, int column) {
    // Check the same column above
    for (int i = 0; i < row; i++) {
        if (board[i][column] == 1) {
            return false;
        }
    }

    // Check the upper-left diagonal
    for (int i = row - 1, j = column - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check the upper-right diagonal
    for (int i = row - 1, j = column + 1; i >= 0 && j < 8; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solve(int row) {
    if (row == 8) {
        return true;
    }

    for (int column = 0; column < 8; column++) {
        if (isSafe(row, column)) {
            board[row][column] = 1;

            if (solve(row + 1)) {
                return true;
            }

            board[row][column] = 0;    // Backtrack
        }
    }

    return false;
}

int main() {
    int firstColumn;

    cout << "Enter the first queen's column (1-8): ";
    cin >> firstColumn;

    if (firstColumn < 1 || firstColumn > 8) {
        cout << "Please enter a column from 1 to 8.\n";
        return 0;
    }

    board[0][firstColumn - 1] = 1;

    if (solve(1)) {
        cout << "8-Queens matrix:\n";

        for (int row = 0; row < 8; row++) {
            for (int column = 0; column < 8; column++) {
                cout << board[row][column] << " ";
            }
            cout << "\n";
        }
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}