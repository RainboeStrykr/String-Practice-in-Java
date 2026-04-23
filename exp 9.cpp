#include <iostream>
using namespace std;

const int MAX = 20;

// Function to check if it's safe to place queen
bool isSafe(int board[MAX][MAX], int row, int col, int n) {
    
    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    // Check left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    // Check right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

// Function to print solution
void printSolution(int board[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Backtracking function
void solveNQueens(int board[MAX][MAX], int row, int n, int &count) {
    if (row == n) {
        cout << "Solution " << ++count << ":\n";
        printSolution(board, n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;   // Place queen

            solveNQueens(board, row + 1, n, count);

            board[row][col] = 0;   // Backtrack
        }
    }
}

int main() {
    int n;
    cout << "Enter number of queens: ";
    cin >> n;

    int board[MAX][MAX] = {0};
    int solutionCount = 0;

    solveNQueens(board, 0, n, solutionCount);

    if (solutionCount == 0) {
        cout << "No solution exists for N = " << n << endl;
    }

    return 0;
}
