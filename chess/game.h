#pragma once
#include "pieces.h"
#include <iostream>
#define GAME_END ~game(); 
namespace game {
	class game {
	private:
	int line, column, newline, newcolumn, role;
    piece::piece*** board ;
	piece::piece*** teams;
	char*** interface_board;
	public:
		void read_input();
		void switch_roles();
		void game_begin();
		void show_interface();
		void update_interface_board();
		game();
		~game() { std::cout << "game has ended"; };
};



};