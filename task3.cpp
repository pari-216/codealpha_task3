#include <iostream>
using namespace std;

#define SIZE 9

// Sudoku puzzle (0 means empty cell)
int board[SIZE][SIZE] = {
    {5,3,0,0,7,0,0,0,0},
    {6,0,0,1,9,5,0,0,0},
    {0,9,8,0,0,0,0,6,0},
    {8,0,0,0,6,0,0,0,3},
    {4,0,0,8,0,3,0,0,1},
    {7,0,0,0,2,0,0,0,6},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,1,9,0,0,5},
    {0,0,0,0,8,0,0,7,9}
};

// Original fixed cells
bool fixedCell[SIZE][SIZE];

// Function to display Sudoku grid
void printBoard() {

    cout << "\n================ SUDOKU GAME ================\n\n";

    for(int i = 0; i < SIZE; i++) {

        if(i % 3 == 0)
            cout << " -----------------------------------------\n";

        for(int j = 0; j < SIZE; j++) {

            if(j % 3 == 0)
                cout << " | ";

            if(board[i][j] == 0)
                cout << ". ";
            else
                cout << board[i][j] << " ";
        }

        cout << " |\n";
    }

    cout << " -----------------------------------------\n";
}

// Function to check whether number can be placed
bool isSafe(int row, int col, int num) {

    // Check row
    for(int x = 0; x < SIZE; x++) {
        if(board[row][x] == num)
            return false;
    }

    // Check column
    for(int x = 0; x < SIZE; x++) {
        if(board[x][col] == num)
            return false;
    }

    // Check 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {

            if(board[startRow + i][startCol + j] == num)
                return false;
        }
    }

    return true;
}

// Check if puzzle is complete
bool isComplete() {

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {

            if(board[i][j] == 0)
                return false;
        }
    }

    return true;
}

int main() {

    // Mark fixed cells
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {

            if(board[i][j] != 0)
                fixedCell[i][j] = true;
            else
                fixedCell[i][j] = false;
        }
    }

    int row, col, num;

    cout << "Welcome to Sudoku Game!\n";
    cout << "Enter row, column and number.\n";
    cout << "Rows and columns are from 1 to 9.\n";

    while(true) {

        printBoard();

        // Check win
        if(isComplete()) {
            cout << "\nCongratulations! Sudoku Solved Successfully!\n";
            break;
        }

        cout << "\nEnter Row (1-9): ";
        cin >> row;

        cout << "Enter Column (1-9): ";
        cin >> col;

        cout << "Enter Number (1-9): ";
        cin >> num;

        // Convert to array indexing
        row--;
        col--;

        // Validation
        if(row < 0 || row >= 9 || col < 0 || col >= 9 || num < 1 || num > 9) {
            cout << "\nInvalid Input! Try again.\n";
            continue;
        }

        // Check fixed cell
        if(fixedCell[row][col]) {
            cout << "\nYou cannot change fixed cells!\n";
            continue;
        }

        // Check valid move
        if(isSafe(row, col, num)) {

            board[row][col] = num;

            cout << "\nNumber inserted successfully!\n";
        }
        else {
            cout << "\nInvalid Move! Number cannot be placed there.\n";
        }
    }

    return 0;
}