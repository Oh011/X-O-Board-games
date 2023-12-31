#include "bits/stdc++.h"
#include "BoardGame_Classes.h"
using namespace std;

five_Tic_Tac_Toe_Board::five_Tic_Tac_Toe_Board() {

    n_rows=5;
    n_cols=5;

    board=new char *[n_rows];

    for (int i = 0; i <n_rows ; ++i) {
        board[i]=new char [n_cols];
        for (int j = 0; j <n_cols ; ++j) {
            board[i][j] ='0';
        }
    }
}


bool five_Tic_Tac_Toe_Board::update_board(int x, int y, char mark) {

    if ((x>4 ||y>4) || (x<0 || y<0))
        return false;


    else if (board[x][y]!='0'){
        cout<<"This place have a mark\n";
        return false;

    }


    else{


        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
}


bool five_Tic_Tac_Toe_Board::is_winner() {
    if (n_moves<24)
        return false;



    else {


        int count_x = 0;
        int row_x = 1;
        int col_x = 1;
        int diagonal_x = 1;


        for (int i = 0; i <= 4; ++i) {
            for (int j = 0; j <= 3; ++j) {

                if (row_x == 3) {

                    ++count_x;

                    row_x = 1;
                }

                if (board[i][j] == board[i][j + 1] && board[i][j] != '0' && board[i][j] == 'X') {
                    ++row_x;


                } else
                    row_x = 1;


            }
        }

        for (int i = 0; i <= 4; ++i) {
            for (int j = 0; j <= 3; ++j) {

                if (col_x == 3) {

                    ++count_x;

                    col_x = 1;
                }

                if (board[j][i] == board[j + 1][i] && board[j][i] != '0' && board[j][i] == 'X')
                    ++col_x;

                else
                    col_x = 1;
            }
        }

        int r = 0;
        int c;

        for (int i = 0; i <= 2; ++i) {
            c = i;
            for (int j = 0; j < 4; ++j) {


                if (diagonal_x == 3) {

                    ++count_x;
                    diagonal_x = 1;
                }

                if (i == 1 && r == 3)
                    break;

                if (i == 2 && r == 2)
                    break;


                if (board[r][c] == board[r + 1][c + 1] && board[r][c] != '0' && board[r][c] == 'X') {
                    ++diagonal_x;
                    ++r;
                    ++c;

                } else {
                    diagonal_x = 1;
                    ++r;
                    ++c;

                }
            }
            r = 0;
        }


        diagonal_x = 1;
        r = 0;
        c = 0;

        for (int i = 1; i <= 2; ++i) {
            r = i;
            for (int j = 0; j < 3; ++j) {

                if (diagonal_x == 3) {


                    ++count_x;
                    diagonal_x = 1;
                }
                if (i == 2 && r == 4)
                    break;


                if (board[r][c] == board[r + 1][c + 1] && board[r][c] != '0' && board[r][c] == 'X') {
                    ++diagonal_x;
                    ++r;
                    ++c;
                } else {
                    diagonal_x = 1;
                    ++r;
                    ++c;
                }


            }
            c = 0;

        }


        r = 0;
        c = 0;
        diagonal_x = 1;


        for (int i = 2; i <= 4; ++i) {
            r = i;
            for (int j = 0; j < 4; ++j) {

                if (diagonal_x == 3) {

                    ++count_x;
                    diagonal_x = 1;
                }
                if (i == 2 && r == 0)
                    break;


                if (i == 3 && r == 0)
                    break;


                if (board[r][c] == board[r - 1][c + 1] && board[r][c] != '0' && board[r][c] == 'X') {
                    ++diagonal_x;
                    --r;
                    ++c;
                } else {
                    diagonal_x = 1;
                    --r;
                    ++c;
                }


            }

            c = 0;
        }


        r = 4;
        c = 0;
        diagonal_x = 0;

        for (int i = 1; i <= 2; ++i) {
            c = i;
            for (int j = 0; j < 3; ++j) {

                if (diagonal_x == 3) {


                    ++count_x;
                    diagonal_x = 1;
                }
                if (i == 2 && r == 2)
                    break;


                else {
                    if (board[r][c] == board[r - 1][c + 1] && board[r][c] != '0' && board[r][c] == 'X') {
                        ++diagonal_x;
                        --r;
                        ++c;
                    } else {
                        diagonal_x = 1;
                        --r;
                        ++c;
                    }

                }
            }

            r = 4;
        }

        int count_o = 0;
        int row_o = 1;
        int col_o = 1;
        int diagonal_o = 1;


        for (int i = 0; i <= 4; ++i) {
            for (int j = 0; j <= 3; ++j) {

                if (row_o == 3) {

                    ++count_o;
                    row_o = 1;
                }

                if (board[i][j] == board[i][j + 1] && board[i][j] != '0' && board[i][j] == 'O')
                    ++row_o;

                else
                    row_o = 1;


            }
        }


        for (int i = 0; i <= 4; ++i) {
            for (int j = 0; j <= 3; ++j) {

                if (col_o == 3) {

                    ++count_o;
                    col_o = 1;
                }

                if (board[j][i] == board[j + 1][i] && board[j][i] != '0' && board[j][i] == 'O')
                    ++col_o;

                else
                    col_o = 1;
            }
        }

        r = 0;
        c = 0;


        for (int i = 0; i <= 2; ++i) {
            c = i;
            for (int j = 0; j < 4; ++j) {

                if (diagonal_o == 3) {


                    ++count_o;
                    diagonal_o = 1;
                }
                if (i == 1 && r == 3)
                    break;

                if (i == 2 && r == 2)
                    break;


                if (board[r][c] == board[r + 1][c + 1] && board[r][c] != '0' && board[r][c] == 'O') {
                    ++diagonal_o;
                    ++r;
                    ++c;

                } else {
                    diagonal_o = 1;
                    ++r;
                    ++c;

                }


            }

            r = 0;
        }


        diagonal_o = 1;
        r = 0;
        c = 0;
 for (int i = 1; i <= 2; ++i) {
            r = i;
            for (int j = 0; j < 3; ++j) {

                if (diagonal_o == 3) {

                    ++count_o;
                    diagonal_o = 1;
                }

                if (i == 2 && r == 4)
                    break;


                if (board[r][c] == board[r + 1][c + 1] && board[r][c] != '0' && board[r][c] == 'O') {
                    ++diagonal_o;
                    ++r;
                    ++c;
                } else {
                    diagonal_o = 1;
                    ++r;
                    ++c;
                }


            }
            c = 0;


        }


        r = 0;
        c = 0;
        diagonal_o = 1;


        for (int i = 2; i <= 4; ++i) {
            r = i;
            for (int j = 0; j < 4; ++j) {


                if (diagonal_o == 3) {


                    ++count_o;
                    diagonal_o = 1;
                }
                if (i == 2 && r == 0)
                    break;

                if (i == 3 && r == 0)
                    break;


                if (board[r][c] == board[r - 1][c + 1] && board[r][c] != '0' && board[r][c] == 'O') {
                    ++diagonal_o;
                    --r;
                    ++c;
                } else {
                    diagonal_o = 1;
                    --r;
                    ++c;
                }


            }

            c = 0;
        }


        r = 4;
        c = 0;
        diagonal_o = 0;

        for (int i = 1; i <= 2; ++i) {
            c = i;
            for (int j = 0; j < 3; ++j) {

                if (diagonal_o == 3) {


                    ++count_o;
                    diagonal_o = 1;
                }


                if (i == 2 && r == 2)
                    break;


                if (board[r][c] == board[r - 1][c + 1] && board[r][c] != '0' && board[r][c] == 'O') {
                    ++diagonal_o;
                    --r;
                    ++c;
                } else {
                    diagonal_o = 1;
                    --r;
                    ++c;
                }


            }

            r = 4;
        }

        if (count_x > count_o){
            cout<<"Player with symbol X is winner\n";
            return true;
        }

        else if (count_o > count_x){
            cout<<"Player with symbol O is winner\n";
            return true;
        }

        else if(count_x == count_o){
            return false;
        }

        return false;



    }


}


bool five_Tic_Tac_Toe_Board::game_is_over() {
    return n_moves==24;
}


bool five_Tic_Tac_Toe_Board::is_draw() {
    return (n_moves==24 && !is_winner());
}

void five_Tic_Tac_Toe_Board::display_board() {

    cout<<"  0   1   2   3   4   \n";
    cout<<"=========================\n";


    for (int i = 0; i <5 ; ++i) {
        cout<<i<<"|";


        for (int j = 0; j <5 ; ++j) {

            if (board[i][j]=='0')
                cout<<"   |";


            else
                cout << " " << board[i][j] << " |";

        }

        cout<<endl;


    }
    cout<<"==============================\n";

}








