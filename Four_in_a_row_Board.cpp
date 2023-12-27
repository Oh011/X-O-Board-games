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
bool Four_in_a_row_Board::is_winner() {
const int rows = 6;
    const int cols = 7;
    // Check for horizontal and vertical wins
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            char currentCell = board[i][j];

            // Horizontal win check
            if (j + 3 < cols &&
                currentCell != '0' &&
                currentCell == board[i][j + 1] &&
                currentCell == board[i][j + 2] &&
                currentCell == board[i][j + 3]) {
                return true;
            }

            // Vertical win check
            if (i + 3 < rows &&
                currentCell != '0' &&
                currentCell == board[i + 1][j] &&
                currentCell == board[i + 2][j] &&
                currentCell == board[i + 3][j]) {
                return true;
            }
        }
    }

    // Check for diagonal wins
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            char currentCell = board[i][j];

            // Diagonal win checks
            if (j + 3 < cols && i + 3 < rows) {
                if (currentCell != '0' &&
                    currentCell == board[i + 1][j + 1] &&
                    currentCell == board[i + 2][j + 2] &&
                    currentCell == board[i + 3][j + 3]) {
                    return true;
                }
            }

            if (j - 3 >= 0 && i + 3 < rows) {
                if (currentCell != '0' &&
                    currentCell == board[i + 1][j - 1] &&
                    currentCell == board[i + 2][j - 2] &&
                    currentCell == board[i + 3][j - 3]) {
                    return true;
                }
            }
        }
    }

    return false;
}
bool Four_in_a_row_Board::is_draw() {
    return (n_moves ==42 && !is_winner());
}

void Four_in_a_row_Board::display_board() {
    cout<<"  0   1   2   3   4   5   6\n";
    cout<<"==============================\n";


    for (int i = 0; i <6 ; ++i) {
        cout<<i<<"|";


        for (int j = 0; j <7 ; ++j) {

            if (board[i][j]=='0')
                cout<<"   |";


            else
                cout << " " << board[i][j] << " |";

        }
        cout<<endl;
    }
    cout<<"==============================\n";


}

bool Four_in_a_row_Board::game_is_over() {
    return n_moves==42;
}
