#include <iostream>
#include <stdlib.h>
#include "pieces.h"
#include "game.h"

int main(){
    game::game Game;
    Game.show_interface();
    /*while ((piece::in_check_mate(teams[role][0], teams, board) == false) && (piece::in_stale_mate(teams[role][0], teams, board) == false)) {
    
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
    }*/
    Game.game_begin();
    Game.~Game();
}