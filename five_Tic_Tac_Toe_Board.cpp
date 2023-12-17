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

