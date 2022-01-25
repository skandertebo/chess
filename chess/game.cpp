#include "game.h"
namespace game {
	game::game() {
		int i, j;
		column = 0; line = 0; role = white; newline = 0; newcolumn = 0;
		teams = new piece::piece * *[2];
		*teams = new piece::piece * [16];
		*(teams + 1) = new piece::piece * [16];
		role = white;
		board = new piece::piece * *[8];
		for (j = 0; j < 8; j++)*(board + j) = new piece::piece * [8];
		for (i = 0; i < 8; i++) {
			for (j = 0; j < 8; j++)board[i][j] = nullptr;
		}
		for (i = 8; i < 16; i++) {
			teams[white][i] = new piece::pawn(white, 1, i - 8, alive, 0, i, 'p' , 9);
		}
		teams[white][0] = new piece::king(white, 0, 4, alive, 0, 0, 'u' , 0);
		teams[white][1] = new piece::queen(white, 0, 3, alive, 0, 1, 'q' , 0);
		teams[white][2] = new piece::rook(white, 0, 0, alive, 0, 2, 'r' , 1);
		teams[white][3] = new piece::rook(white, 0, 7, alive, 0, 3, 'r' ,2);
		teams[white][4] = new piece::knight(white, 0, 1, alive, 0, 4, 'k' , 1);
		teams[white][5] = new piece::knight(white, 0, 6, alive, 0, 5, 'k' , 2);
		teams[white][6] = new piece::bishop(white, 0, 2, alive, 0, 5, 'b' , 1);
		teams[white][7] = new piece::bishop(white, 0, 5, alive, 0, 5, 'b' , 2);

		for (i = 8; i < 16; i++) {
			teams[black][i] = new piece::pawn(black, 6, i - 8, alive, 0, i, 'p' , 9);
		}
		teams[black][0] = new piece::king(black, 7, 4, alive, 0, 0, 'u' , 0);
		teams[black][1] = new piece::queen(black, 7, 3, alive, 0, 1, 'q' , 0);
		teams[black][2] = new piece::rook(black, 7, 0, alive, 0, 2, 'r' ,1);
		teams[black][3] = new piece::rook(black, 7, 7, alive, 0, 3, 'r' ,2);
		teams[black][4] = new piece::knight(black, 7, 1, alive, 0, 4, 'k',1);
		teams[black][5] = new piece::knight(black, 7, 6, alive, 0, 5, 'k',2);
		teams[black][6] = new piece::bishop(black, 7, 2, alive, 0, 6, 'b',1);
		teams[black][7] = new piece::bishop(black, 7, 5, alive, 0, 7, 'b',2);

		for (j = 0; j < 16; j++) {
			board[teams[white][j]->getline()][teams[white][j]->getcolumn()] = teams[white][j];
			board[teams[black][j]->getline()][teams[black][j]->getcolumn()] = teams[black][j];
		}
		interface_board = new char** [8];
		for (i = 0; i < 8; i++) {
			*(interface_board + i) = new char* [8];
			for (j = 0; j < 8; j++) {
				*(*(interface_board + i) + j) = new char[3];
				(*(*(interface_board + i) + j))[0] = ((board[i][j] == nullptr) ? ' ' : ((board[i][j]->getcolor()==0)? 'w' : 'b'));
				(*(*(interface_board + i) + j))[1] = ((board[i][j] == nullptr) ? ' ' : board[i][j]->getprom());
				(*(*(interface_board + i) + j))[2] = ((board[i][j] == nullptr) ? ' ' :  ((board[i][j]->getnumber()==1)?'1':(board[i][j]->getnumber()==0)?'0': (board[i][j]->getnumber() == 2)?'2':'3'));
			}
		}
    }
	void game::show_interface() {
		int i, j; 
		//std::cout << ((role == white)?  "white" : "black") << " plays" << std::endl;
		std::cout << "    1   2   3   4   5   6   7   8 " << std::endl;
		std::cout << "----------------------------------" << std::endl;
		for (i = 7; i >= 0; i--) {
			std::cout << i+1 << " |";
			for (j = 0; j < 8; j++) {
			
				std::cout << interface_board[i][j][0] << interface_board[i][j][1] << interface_board[i][j][2] << "|";
			}
			std::cout << std::endl;
			std::cout << "---------------------------------" << std::endl;
		}
	}
	void game::read_input() {
		do {
			std::cout << "choose line" << std::endl;
			std::cout << "choose column" << std::endl;
			std::cin >> line;
			std::cin >> column;
			line--;
			column--;
		} while ((line > 7) || (column > 7) || (board[line][column] == nullptr) || (board[line][column]->getcolor() != role));

		do {
			std::cout << "choose new line" << std::endl;
			std::cout << "choose new column" << std::endl;
			std::cin >> newline;
			std::cin >> newcolumn;
			newline--;
			newcolumn--;
		} while ((board[line][column]->valid_move(newline, newcolumn, board) == 0) || ((board[line][column]->check_validity(newline, newcolumn, board, teams) == 0)));
	}
	void game :: switch_roles(){ role = (role + 1) % 2; }
	void game::update_interface_board() {
		int i, j;
		for (i = 0; i < 8; i++) {
			for (j = 0; j < 8; j++) {
				(*(*(interface_board + i) + j))[0] = ((board[i][j] == nullptr) ? ' ' : ((board[i][j]->getcolor() == 0) ? 'w' : 'b'));
				(*(*(interface_board + i) + j))[1] = ((board[i][j] == nullptr) ? ' ' : board[i][j]->getprom());
				(*(*(interface_board + i) + j))[2] = ((board[i][j] == nullptr) ? ' ' : ((board[i][j]->getnumber() == 1) ? '1' : (board[i][j]->getnumber() == 0) ? '0' : (board[i][j]->getnumber() == 2) ? '2' : '3'));
			}
		}
	}
	void game :: game_begin() {
		int i,j;
		while ((piece::in_check_mate(teams[role][0], teams, board) == false) && (piece::in_stale_mate(teams[role][0], teams, board) == false)) {
			read_input();
			board[line][column]->move(newline, newcolumn, board);
			switch_roles();
			update_interface_board();
			show_interface();
			if (piece::in_check(teams[role][0] , teams[(role+1)%2] , board) == 1)std::cout << ((role == 0) ? "white in check" : "black in check") << std::endl;
			std::cout << ((role == 0) ? "white turn" : "black turn") << std::endl;
		}
	
	/**
	for (i = 0; i < 16; i++) {

		std::cout << "WHITE : index: " << teams[0][i]->getindice() << " line: " << teams[0][i]->getline() << " column: " << teams[0][i]->getcolumn() << " status " << teams[0][i]->getstatus()
			<< "|| BLACK : index: " << teams[1][i]->getindice() << " line: " << teams[1][i]->getline() << " column: " << teams[1][i]->getcolumn() << " status " << teams[1][i]->getstatus() << std::endl;
	}*/

		}





};