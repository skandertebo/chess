#include "pieces.h"
namespace piece {
bool rook :: valid_move(int newline , int newcolumn , piece***board){
	int i;
	if ((newline > 7) || (newcolumn) > 7) return false;
	if ((line != newline) && (column != newcolumn)) return false;
	if ((line == newline) && (column == column)) return false;
	if ((board[newline][newcolumn] != nullptr) && (board[newline][newcolumn]->getcolor() == color))return false;
	if (newline > line) {
		for (i = line + 1; i < newline; i++) {
			if (board[i][column] != nullptr) return false;
		}
		



	}
}
bool pawn :: valid_move(int newline , int newcolumn , piece***board){
	return 0;
}
bool bishop :: valid_move(int newline , int newcolumn , piece***board){
	return 0;
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

void promote(piece* pwn , char prom){
	if(pwn->prom == 'p'){
	switch (prom) {
	case 'r':
	{rook extra(pwn->getcolor(), pwn->getline(), pwn->getcolumn(), pwn->getstatus()); 
	delete pwn;
	*pwn = rook(extra);
	};
	break;

	case 'k':
	{knight extra(pwn->getcolor(), pwn->getline(), pwn->getcolumn(), pwn->getstatus()); 
	delete pwn;
	*pwn = knight(extra);
	};
	break;

	case 'q':
	{queen extra(pwn->getcolor(), pwn->getline(), pwn->getcolumn(), pwn->getstatus()); 
	delete pwn;
	*pwn = queen(extra);
	};
	break;

	case 'b':
	{bishop extra(pwn->getcolor(), pwn->getline(), pwn->getcolumn(), pwn->getstatus());
	delete pwn;
	*pwn = bishop(extra);
	};
	break;
	}
    }
	

 };
