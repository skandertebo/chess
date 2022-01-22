#include <iostream>
#include <stdlib.h>
#include "pieces.h"

int main(){
    bool test=false;
    int role = white;
    int i=0, j;
    int line, column , newline , newcolumn;
    piece::piece*** teams = new piece :: piece ** [2];
    *teams = new piece::piece*[16];
    *(teams + 1) = new piece::piece*[16];
    piece::piece*** board = new piece::piece * *[8];
    for (j = 0; j < 8; j++)*(board + j) = new piece::piece * [8];
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++)board[i][j] = nullptr;
    }
        i = 0;
    for (i = 8; i < 16; i++) {
        teams[white][i] = new piece::pawn(white, 1, i-8, alive, 0 , i ,'p');
    }
    teams[white][0] = new piece::king(white, 0, 4, alive, 0, 0, 'k');
    teams[white][1] = new piece::queen(white, 0, 3, alive, 0, 1, 'q');
    teams[white][2] = new piece::rook(white, 0, 0, alive, 0, 2, 'r');
    teams[white][3] = new piece::rook(white, 0, 7 , alive, 0, 3, 'r');
    teams[white][4] = new piece::knight(white, 0, 1, alive, 0, 4, 'k');
    teams[white][5] = new piece::knight(white, 0, 6, alive, 0, 5, 'k');
    teams[white][6] = new piece::bishop(white, 0, 2, alive, 0, 5, 'b');
    teams[white][7] = new piece::bishop(white, 0, 5, alive, 0, 5, 'b');


    for (i = 8; i < 16; i++) {
        teams[black][i] = new piece::pawn(black, 6, i - 8, alive, 0, i, 'p');
    }
    teams[black][0] = new piece::king(black, 7, 4, alive, 0, 0, 'k');
    teams[black][1] = new piece::queen(black, 7, 3, alive, 0, 1, 'q');
    teams[black][2] = new piece::rook(black, 7, 0, alive, 0, 2, 'r');
    teams[black][3] = new piece::rook(black, 7, 7, alive, 0, 3, 'r');
    teams[black][4] = new piece::knight(black, 7, 1, alive, 0, 4, 'k');
    teams[black][5] = new piece::knight(black, 7, 6, alive, 0, 5, 'k');
    teams[black][6] = new piece::bishop(black, 7, 2, alive, 0, 6, 'b');
    teams[black][7] = new piece::bishop(black, 7, 5, alive, 0, 7, 'b');
    
       
   
    for (j = 0; j < 16; j++) {
        board[teams[white][j]->getline()][teams[white][j]->getcolumn()] = teams[white][j];
        board[teams[black][j]->getline()][teams[black][j]->getcolumn()] = teams[black][j];
    }

    while ((piece::in_check_mate(teams[role][0], teams, board) == false) && (piece::in_stale_mate(teams[role][0], teams, board) == false)){
    
        do {
            std::cout << "choose line" << std::endl;
            std::cout << "choose column" << std::endl;
            std::cin >> line;
            std::cin >> column;
        } while ((line > 7) || (column > 7) || (board[line][column] == nullptr) || (board[line][column]->getcolor() != role));

        do {
            std::cout << "choose new line" << std::endl;
            std::cout << "choose new column" << std::endl;
            std::cin >> newline;
            std::cin >> newcolumn;

        } while ((board[line][column]->valid_move(newline, newcolumn, board) == 0) || ((board[line][column]->check_validity(newline, newcolumn, board, teams) == 0)));
        board[line][column]->move(newline, newcolumn, board);
        role = (role + 1) % 2;
        std::cout << ( (role == 0) ? "white turn" : "black turn" ) << std::endl;
        for (i = 0; i < 16; i++) {

            std::cout << "WHITE : index: " << teams[0][i]->getindice() << " line: " << teams[0][i]->getline() << " column: " << teams[0][i]->getcolumn() << " status " << teams[0][i]->getstatus()
                << "|| BLACK : index: " << teams[1][i]->getindice() << " line: " << teams[1][i]->getline() << " column: " << teams[1][i]->getcolumn() << " status " << teams[1][i]->getstatus() << std::endl;
        }
    }
}