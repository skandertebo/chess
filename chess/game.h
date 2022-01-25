#pragma once
#include "pieces.h"
#include <iostream>
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
		game();
		~game() { std::cout << "game has ended"; };
};



};