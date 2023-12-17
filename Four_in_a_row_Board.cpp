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

    int horzontal_win=1;


    // Check for horizontal wins and loop through rows
    for (int i = 0; i <=5 ; ++i) {
        for (int j = 0; j <6 ; ++j) {

            if (horzontal_win == 4)
                return true;

            if (board[i][j]==board[i][j+1] && board[i][j]!='0')
                ++horzontal_win;


            else
                horzontal_win=1;

        }
    }

    if (horzontal_win == 4) {
        return true;
    }
    int column_win=1;


    for (int i = 0; i <=6 ; ++i) {
        for (int j = 0; j <=4 ; ++j) {

            if (column_win == 4)
                return true;

            if (board[j][i]==board[j+1][i]  && board[j][i]!='0')
                ++column_win;

            else
                column_win=1;

        }
    }


    if (column_win == 4)
        return true;


    int diagonal_win=1;

    int r=0;
    int c=0;


    for (int i = 0; i <=3 ; ++i) {
        c=i;
        for (int j = 0; j <5 ; ++j) {

            if (diagonal_win == 4)
                return true;


            if (i==1 && r==5)
                break;

            if (i==2 && r==4)
                break;

            if(i==3 && r==3 )
                break;

            else{

                if (board[r][c]==board[r+1][c+1] && board[r][c]!='0'){
                    ++diagonal_win;
                    ++r;
                    ++c;
                }

                else{

                    diagonal_win=1;
                    ++r;
                    ++c;
                }
            }
        }

        r=0;
    }

    if (diagonal_win == 4)
        return true;

    r=0;
    c=0;
    diagonal_win=1;


    for (int i =1; i <=2 ; ++i) {
        r=i;
        for (int j = 0; j <4 ; ++j) {

            if (diagonal_win == 4)
                return true;


            if (i==2 && r==5)
                break;


            else{
                if (board[r][c]==board[r+1][c+1] && board[r][c]!='0'){
                    ++diagonal_win;
                    ++r;
                    ++c;

                }

                else{
                    diagonal_win=1;
                    ++r;
                    ++c;
                }
            }


        }
        c=0;
    }

    if (diagonal_win == 4)
        return true;

    r=0;
    c=0;


    for (int i =3; i <=6 ; ++i) {
        c=i;
        for (int j = 0; j <5 ; ++j) {

            if (diagonal_win == 4)
                return true;

            if (i==3 && r==3)
                break;

            if (i==4 && r==4)
                break;



            else{
                if (board[r][c]==board[r+1][c-1] && board[r][c]!='0'){
                    ++diagonal_win;
                    ++r;
                    --c;

                }

                else{
                    diagonal_win=1;
                    ++r;
                    --c;
                }
            }

        }
        r=0;
    }

    if (diagonal_win == 4)
        return true;

    r=5;
    c=0;
    diagonal_win=1;

    for (int i = 2; i <=3 ; ++i) {
        c=i;

        for (int j = 0; j <4 ; ++j) {


            if (diagonal_win == 4)
                return true;

            if (i==3 && r==2)
                break;

            else{
                if (board[r][c]==board[r-1][c+1] && board[r][c]!='0'){
                    ++c;
                    --r;
                    ++diagonal_win;
                }

                else{
                    ++c;
                    --r;
                    diagonal_win=1;
                }
            }
        }
        r=5;
    }

    if (diagonal_win == 4)
        return true;


    return false;
}
