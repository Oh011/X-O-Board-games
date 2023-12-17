Four_in_a_row_Board::Four_in_a_row_Board() {

    n_rows=6;
    n_cols=7;

    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] ='0';
    }

}
bool Four_in_a_row_Board::update_board(int x, int y, char mark) {
    // Check if the given coordinates are within the valid range
    if ((x > 5 || y > 6) || (x < 0 || y < 0))
        return false;

    // Check if the space below is empty for a valid move
    if (x < 5 && board[x + 1][y] == '0')
        return false;

    // Check if the current position is already marked
    if (board[x][y] != '0') {
        cout << "This place has a mark\n";
        return false;
    }
    else {
        // Update the board with the player's mark
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
}
