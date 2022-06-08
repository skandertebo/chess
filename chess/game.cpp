#include "game.h"

	game::game::game() {
		active_game = true;
		heldPiece = nullptr;
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
			teams[white][i] = new piece::pawn(white, 1, i - 8, alive, 0, i, 'p', 9);
		}
		teams[white][0] = new piece::king(white, 0, 4, alive, 0, 0, 'u', 0);
		teams[white][1] = new piece::queen(white, 0, 3, alive, 0, 1, 'q', 0);
		teams[white][2] = new piece::rook(white, 0, 0, alive, 0, 2, 'r', 1);
		teams[white][3] = new piece::rook(white, 0, 7, alive, 0, 3, 'r', 2);
		teams[white][4] = new piece::knight(white, 0, 1, alive, 0, 4, 'k', 1);
		teams[white][5] = new piece::knight(white, 0, 6, alive, 0, 5, 'k', 2);
		teams[white][6] = new piece::bishop(white, 0, 2, alive, 0, 6, 'b', 1);
		teams[white][7] = new piece::bishop(white, 0, 5, alive, 0, 7, 'b', 2);

		for (i = 8; i < 16; i++) {
			teams[black][i] = new piece::pawn(black, 6, i - 8, alive, 0, i, 'p', 9);
		}
		teams[black][0] = new piece::king(black, 7, 4, alive, 0, 0, 'u', 0);
		teams[black][1] = new piece::queen(black, 7, 3, alive, 0, 1, 'q', 0);
		teams[black][2] = new piece::rook(black, 7, 0, alive, 0, 2, 'r', 1);
		teams[black][3] = new piece::rook(black, 7, 7, alive, 0, 3, 'r', 2);
		teams[black][4] = new piece::knight(black, 7, 1, alive, 0, 4, 'k', 1);
		teams[black][5] = new piece::knight(black, 7, 6, alive, 0, 5, 'k', 2);
		teams[black][6] = new piece::bishop(black, 7, 2, alive, 0, 6, 'b', 1);
		teams[black][7] = new piece::bishop(black, 7, 5, alive, 0, 7, 'b', 2);

		for (j = 0; j < 16; j++) {
			board[teams[white][j]->getline()][teams[white][j]->getcolumn()] = teams[white][j];
			board[teams[black][j]->getline()][teams[black][j]->getcolumn()] = teams[black][j];
		}
	}
	
	void game::game::switch_roles() { role = (role + 1) % 2; }

	void game::game::game_begin() {

		gui::board* bd = new gui::board();
		gui::board& Board = *bd;
		gui::piece* teams[2][16];
		int isHeld = 0;
		gui::initiate_teams(teams);
		sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
		while (window.isOpen())
		{

			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				if (event.type == sf::Event::MouseButtonPressed)
				{
					if ((event.mouseButton.button == sf::Mouse::Left)&&(active_game))
					{
						int col = (int)event.mouseButton.x / 100;
						int row = 7 - ((int)event.mouseButton.y / 100);
						std::cout << row << " " << col << " " << board[row][col] << std::endl;
						if (!isHeld) {

							if (board[row][col]) {
								if (role == board[row][col]->getcolor()) {
									isHeld = 1;
									heldPiece = board[row][col];
								}
							}
							
						}
						else {
							if ((heldPiece->valid_move(row, col, board))  && (heldPiece->check_validity(row, col, board, this->teams))) {
								
								if (board[row][col]) {
									std::cout << "eating";
									teams[!role][board[row][col]->getindice()]->kill();
								}
								if (heldPiece->getprom() == 'u') {
									if (col == heldPiece->getcolumn() + 2) {
										teams[role][3]->move(5, row);
									}
									else if (col == heldPiece->getcolumn() - 2) {
										teams[role][2]->move(3, row);
									}
								}
								teams[role][heldPiece->getindice()]->move(col, row);
								heldPiece->move(row, col, board);
								if (piece::in_check_mate(this->teams[!role][0], this->teams, board)) {
									active_game = 0;
									role == white ?std::cout << "white wins!" << std::endl : std::cout << "black wins"<<std::endl;
								}
								else if (piece::in_stale_mate(this->teams[!role][0], this->teams, board)) {
									active_game = 0;
									std::cout << "draw by stalemate!" << std::endl;
								}
								else
								switch_roles();
							
							}
							
							heldPiece = nullptr;
							isHeld = 0;
						}
					}
				}
			}
			window.clear();
			Board.draw(window);
			gui::piece::drawPieces(teams, window);
			window.display();
		}
	}
