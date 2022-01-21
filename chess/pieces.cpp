#include "pieces.h"
namespace piece {
	
bool rook :: valid_move(int newline , int newcolumn , piece***board){
	int i;
	piece* temp = this ;
	if ((newline > 7) || (newcolumn) > 7) return false;
	if ((line != newline) && (column != newcolumn)) return false;
	if ((line == newline) && (column == column)) return false;
	if ((board[newline][newcolumn] != nullptr) && (board[newline][newcolumn]->getcolor() == color))return false;
	if (newline > line) {
		for (i = line + 1; i < newline; i++) {
			if (board[i][column] != nullptr) return false;
		}
	}
	else if (newline < line) {
		for (i = line - 1; i > newline; i--) {
			if (board[i][column] != nullptr) return false;
		}
	}
	else if (newcolumn < column) {
		for (i = column - 1; i > newcolumn; i--) {
			if (board[line][i] != nullptr) return false;
		}
	}

	else if (newcolumn > column) {
		for (i = column + 1; i < newcolumn; i++) {
			if (board[line][i] != nullptr) return false;
		}

	}
	
	return true;
}
bool pawn :: valid_move(int newline , int newcolumn , piece***board){
	if ((newline > 7) || (newcolumn) > 7) return false;
	if (newline <= line) return false;
	if ((newline > line + 2)||(newcolumn > column + 1)||(newcolumn < column - 1)) return false;
	if ((board[newline][newcolumn] != nullptr) && (board[newline][newcolumn]->getcolor() == color))return false;
	if (newline == line + 1) {
	if (((newcolumn == column - 1) || (newcolumn == column + 1)) && (board[newline][newcolumn] == nullptr)) return false;
	if ((newcolumn == column) && (board[newline][newcolumn] != nullptr))return false;
	return true;
	}
	else {
		
			if (newcolumn != column)return false;
			if (board[line + 1][column] != nullptr)return false;
			if (board[newline][newcolumn] != nullptr) return false;

			return true;
	}
}
bool bishop :: valid_move(int newline , int newcolumn , piece***board){
	if ((newline > 7) || (newcolumn) > 7) return false;
	if ((board[newline][newcolumn] != nullptr) && (board[newline][newcolumn]->getcolor() == color))return false;
}
bool queen :: valid_move(int newline , int newcolumn , piece***board){
	return 0;
}
bool king :: valid_move(int newline , int newcolumn , piece***board){
	return 0;
}
bool knight :: valid_move(int newline , int newcolumn , piece***board){
	return 0;
}
bool in_check(const king& kng) { return 0; }
void promote(piece* pwn, char prom) {
	
		if (pwn->getprom() == 'p') {
			switch (prom) {
			case 'r':
			{rook extra(pwn->getcolor(), pwn->getline(), pwn->getcolumn(), pwn->getstatus() , pwn->getmove_count());
			delete pwn;
			*pwn = rook(extra);
			};
			break;

			case 'k':
			{knight extra(pwn->getcolor(), pwn->getline(), pwn->getcolumn(), pwn->getstatus(), pwn->getmove_count());
			delete pwn;
			*pwn = knight(extra);
			};
			break;

			case 'q':
			{queen extra(pwn->getcolor(), pwn->getline(), pwn->getcolumn(), pwn->getstatus(), pwn->getmove_count());
			delete pwn;
			*pwn = queen(extra);
			};
			break;

			case 'b':
			{bishop extra(pwn->getcolor(), pwn->getline(), pwn->getcolumn(), pwn->getstatus(), pwn->getmove_count());
			delete pwn;
			*pwn = bishop(extra);
			};
			break;
			}
		}
	}
 
 };
