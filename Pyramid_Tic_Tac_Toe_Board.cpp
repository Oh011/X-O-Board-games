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
