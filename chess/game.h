#pragma once
#include "pieces.h"
#include "UI.h"
#include <iostream>
#define GAME_END ~game(); 
namespace game {
	class game {
	private:
	int line, column, newline, newcolumn, role;
    piece::piece*** board ;
	piece::piece*** teams;
	piece::piece* heldPiece;
	bool active_game;

	public:

		void switch_roles();
		void game_begin();
		game();
		~game() { std::cout << "game has ended"; };
};



};