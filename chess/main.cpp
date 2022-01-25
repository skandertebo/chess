#include <iostream>
#include <stdlib.h>
#include "pieces.h"
#include "game.h"

int main(){
    game::game Game;
    Game.show_interface();
    /*
        for (i = 0; i < 16; i++) {

            std::cout << "WHITE : index: " << teams[0][i]->getindice() << " line: " << teams[0][i]->getline() << " column: " << teams[0][i]->getcolumn() << " status " << teams[0][i]->getstatus()
                << "|| BLACK : index: " << teams[1][i]->getindice() << " line: " << teams[1][i]->getline() << " column: " << teams[1][i]->getcolumn() << " status " << teams[1][i]->getstatus() << std::endl;
        }
    }*/
    Game.game_begin();
    Game.GAME_END
}