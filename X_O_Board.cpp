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
