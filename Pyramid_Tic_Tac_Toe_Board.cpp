// Implementation of Pyramid Tic-Tac-Toe_Board class methods
// File: Pyramid_Tic_Tac_Toe_Board.cpp
// Author: Omar Hisham Abdallah.
// Section: s17
// ID: 20220235
// TA: Rana Abdelkader
// Date: 10 DEC 2023

#include "bits/stdc++.h"
#include "BoardGame_Classes.h"
#include "Pyramid_Tic_Tac_Toe_Board.h"
using namespace std;


// Constructor for Pyramid_Tic_Tac_Toe_Board
Pyramid_Tic_Tac_Toe_Board::Pyramid_Tic_Tac_Toe_Board() {
    n_rows = 3;
    n_cols = 5;

    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {

        board[i] = new char[n_cols];

        // Initialize the board with '0' (empty)
        for (int j = 0; j < n_cols; j++)
            board[i][j] = '0';
    }
}

// Update the game board with the player's move
bool Pyramid_Tic_Tac_Toe_Board::update_board(int x, int y, char mark) {

    // Check if the move is within the valid boundaries
    if (x == 0 && y != 2)
        return false;

    if (x == 1 && (y == 4 || y == 0))
        return false;

    if ((x < 0 || y < 0) || (x > 2 || y > 4))
        return false;

        // Check if the chosen cell is not empty
    else if (board[x][y] != '0' ) {
        cout << "This place has a mark\n";
        return false;
    }

        // Valid move, update the board
    else {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }

}



// Check if there is a winner on the Pyramid Tic-Tac-Toe board
bool Pyramid_Tic_Tac_Toe_Board::is_winner() {



    // Check for column win and loop through column 2
    int col_win = 1;
    for (int i = 0; i <= 1; ++i) {
        if (board[i][2] == board[i + 1][2] && (board[i][2] != '0'))
            ++col_win;
    }

// if we get three consecutive equal marks in column 2 then it is considered a win.
    if (col_win == 3)
        return true;

    // Check for row win and  loop through row 1
    int row_win = 1;
    for (int i = 1; i <= 2; ++i) {
        if (board[1][i] == board[1][i + 1] && (board[1][i] != '0'))
            ++row_win;
    }

    // if we get three consecutive equal marks in row 1 then it is considered a win.
    if (row_win == 3)
        return true;


    row_win = 1;

    // Check for row win and  loop through row 2
    for (int i = 0; i <= 3; ++i) {

        if (row_win == 3)
            return true;

        else if (board[2][i] == board[2][i + 1] && board[2][i] != '0')
            ++row_win;
        else
            row_win = 1;
    }

    // if we get three consecutive equal marks in row 2 then it is considered a win.
    if (row_win == 3)
        return true;

    // Check for diagonal wins


    // Check for diagonal wins (top-right to bottom-left)
    if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && board[0][2] != '0')
        return true;

        // Check for diagonal wins (top-left to bottom-right)
    else if ((board[0][2] == board[1][3]) && (board[1][3] == board[2][4]) && board[0][2] != '0')
        return true;

    return false;
}

