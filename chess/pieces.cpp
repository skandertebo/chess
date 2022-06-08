#include "pieces.h"
namespace piece {
	
bool rook :: valid_move(int newline , int newcolumn , piece***board){
	int i;
	if ((newline > 7) || (newcolumn) > 7) return false;
	if ((line != newline) && (column != newcolumn)) return false;
	if ((line == newline) && (column == newcolumn)) return false;
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
		return true;
	}
	else {
		if (newcolumn < column) {
			for (i = column - 1; i > newcolumn; i--) {
				if (board[line][i] != nullptr) return false;
			}
		}

		else  {
			for (i = column + 1; i < newcolumn; i++) {
				if (board[line][i] != nullptr) return false;
			}

		}
		return true;
	}
	return true;
}
bool pawn :: valid_move(int newline , int newcolumn , piece***board){
	if ((newline > 7) || (newcolumn) > 7) return false;
	if (color == white) {
		if (newline <= line) return false;
		if ((newline > line + 2) || (newcolumn > column + 1) || (newcolumn < column - 1)) return false;
		if (board[newline][newcolumn] != nullptr) {
			if (board[newline][newcolumn]->getcolor() == color)return false;
		}

		if (newline == line + 1) {
			if (((newcolumn == column - 1) || (newcolumn == column + 1)) && (board[newline][newcolumn] == nullptr)) return false;
			if ((newcolumn == column) && (board[newline][newcolumn] != nullptr))return false;
			return true;
		}
		else {
			if (move_count != 0)return false;
			if (newcolumn != column)return false;
			if (board[line + 1][column] != nullptr)return false;
			if (board[newline][newcolumn] != nullptr) return false;

			return true;
		}
	}
	else {
		if (newline >= line) return false;
		if ((newline < line - 2) || (newcolumn > column + 1) || (newcolumn < column - 1)) return false;
		if (board[newline][newcolumn] != nullptr) {
			if (board[newline][newcolumn]->getcolor() == color)return false;
		}

		if (newline == line - 1) {
			if (((newcolumn == column - 1) || (newcolumn == column + 1)) && (board[newline][newcolumn] == nullptr)) return false;
			if ((newcolumn == column) && (board[newline][newcolumn] != nullptr))return false;
			return true;
		}
		else {
			if (move_count != 0)return false;
			if (newcolumn != column)return false;
			if (board[line - 1][column] != nullptr)return false;
			if (board[newline][newcolumn] != nullptr) return false;

			return true;
		}


	}
	return true;
}
bool bishop :: valid_move(int newline , int newcolumn , piece***board){
	int i, j;
	if ((newline > 7) || (newcolumn > 7)) return false;
	if ((newline == line) && (newcolumn == column)) return false;
	if ((board[newline][newcolumn] != nullptr) && (board[newline][newcolumn]->getcolor() == color))return false;
	if (((newline - line) != (newcolumn - column)) && ((newline - line) != (column - newcolumn)))return false;
	if (newline > line) {
		if (newcolumn > column) {
			for (i = line + 1, j = column + 1; i < newline; i++, j++) {
				if (board[i][j] != nullptr)return false;
			}
		}
		else {
			for (i = line + 1, j = column - 1; i < newline; i++, j--) {
				if (board[i][j] != nullptr)return false;
			}
		}

	}
	else {
		if (newcolumn > column) {
			for (i = line - 1, j = column + 1; i > newline; i--, j++) {
				if (board[i][j] != nullptr)return false;
			}
		}
		else {
			for (i = line - 1, j = column - 1; i > newline; i--, j--) {
				if (board[i][j] != nullptr)return false;
			}
		}
	}

	return true;
}

bool queen :: valid_move(int newline , int newcolumn , piece***board){
	int i , j;
	COMMON_CHECK
		if ((newline == line) && (newcolumn == column))return false;
	//straight
	if (newline == line) {
		if (newcolumn < column) {
			for (i = column - 1; i > newcolumn; i--) {
				if (board[line][i] != nullptr) return false;
			}
		}

		if (newcolumn > column) {
			for (i = column + 1; i < newcolumn; i++) {
				if (board[line][i] != nullptr) return false;
			}

		}
	}
	else if (newcolumn == column) {
		if (newline > line) {
			for (i = line + 1; i < newline; i++) {
				if (board[i][column] != nullptr) return false;
			}
		}
		else {
			for (i = line - 1; i > newline; i--) {
				if (board[i][column] != nullptr) return false;
			}
		}
	}
	//diagonal
	else {
		if (((newline - line) != (newcolumn - column)) && ((newline - line) != (column - newcolumn)))return false;
		if (newline > line) {
			if (newcolumn > column) {
				for (i = line + 1 , j = column+1; i < newline; i++ ,j++) {
					 if (board[i][j] != nullptr)return false; 
				}
			}
			else {
				for (i = line + 1 , j = column - 1; i < newline; i++ , j--) {
					if (board[i][j] != nullptr)return false; 
				}
			}

		}
		else {
			if (newcolumn > column) {
				for (i = line - 1 , j = column + 1; i > newline; i-- , j++) {
					if (board[i][j] != nullptr)return false; 
				}
			}
			else {
				for (i = line - 1 , j = column - 1; i > newline; i-- ,j--) {
					 if (board[i][j] != nullptr)return false;
				}
			}
		}

	}



	return true;
}
bool king :: valid_move(int newline , int newcolumn , piece***board){

	COMMON_CHECK
	if ((newline == line) && (newcolumn == column)) return false;
	if (newcolumn == column + 2) {
		if (newline != line)return false;
		if (move_count != 0)return false;
		if (board[line][column + 3] == nullptr)return false;
		if (board[line][column + 3]->getprom() != 'r')return false;
		if (board[line][column + 3]->getmove_count() != 0)return false;
		if (board[line][column + 3]->getcolor() != color)return false;
		if (board[line][column + 2]!=nullptr)return false;
		if (board[line][column + 1]!=nullptr)return false;
		castling = king_side;
		return true;
	}
	else if (newcolumn == column - 2) {
		if (newline != line)return false;
		if (move_count != 0)return false;
		if (board[line][column -4] == nullptr)return false;
		if (board[line][column -4]->getprom() != 'r')return false;
		if (board[line][column -4]->getmove_count() != 0)return false;
		if (board[line][column -4]->getcolor() != color)return false;
		if (board[line][column -1] != nullptr)return false;
		if (board[line][column -2] != nullptr)return false;
		if (board[line][column -3] != nullptr)return false;
		return true;
     
	}
	return (((newline - line) <= 1) && ((newline - line) >= -1) && ((newcolumn - column) <= 1) && ((newcolumn - column) >= -1));
	
}
bool knight :: valid_move(int newline , int newcolumn , piece***board){
	COMMON_CHECK
		if ((newcolumn == column + 2) || (newcolumn == column - 2)) {
			if ((newline == line + 1) || (newline == line - 1))return true;
        }
	    if ((newline == line + 2) || (newline == line - 2)) {
		    if ((newcolumn == column + 1) || (newcolumn == column - 1))return true;
	    }
		return false;
}bool piece::check_validity(int newline, int newcolumn, piece***& board , piece***teams) {
	
	piece* oldpiece = board[newline][newcolumn];
	if (board[newline][newcolumn] != nullptr)board[newline][newcolumn]->setstatus(dead);
	int oldline = line;
	int oldcolumn = column;
	int team = (color + 1) % 2;
	int i;
	board[newline][newcolumn] = board[line][column];
	board[line][column] = nullptr;
	column = newcolumn;
	line = newline;
	move_count++;
	for (i = 0; i < 16; i++) {
		if (teams[team][i]->getstatus() == alive) {
			if (teams[team][i]->valid_move(teams[color][0]->getline(), teams[color][0]->getcolumn(), board) == 1) {
				board[oldline][oldcolumn] = board[line][column];
				board[line][column] = nullptr;
				column = oldcolumn;
				line = oldline;
				move_count--;
				return false;
			}
	  }
	}
		board[oldline][oldcolumn] = board[line][column];
		board[line][column] = oldpiece;
		column = oldcolumn;
		line = oldline;
		move_count--;


	return true;
}
bool in_check(piece* kng , piece** team , piece*** board) { 
	
	int i;
	for (i = 0; i < 16; i++) {
		if( (team[i]->valid_move(kng->getline(), kng->getcolumn(), board) == true) && (team[i]->getstatus()==alive))return true;
	}
	return false;
}
void promote(piece*& pwn, char prom) {
	
		if (pwn->getprom() == 'p') {
			switch (prom) {
			case 'r':
			{rook extra(pwn->getcolor(), pwn->getline(), pwn->getcolumn(), pwn->getstatus(), pwn->getmove_count(),pwn->getindice(),'r',pwn->getnumber());
			delete pwn;
			pwn = new rook(extra);
			};
			break;

			case 'k':
			{knight extra(pwn->getcolor(), pwn->getline(), pwn->getcolumn(), pwn->getstatus(), pwn->getmove_count(),pwn->getindice(),'k' , pwn->getnumber());
			delete pwn;
			pwn = new knight(extra);
			};
			break;

			case 'q':
			{queen extra(pwn->getcolor(), pwn->getline(), pwn->getcolumn(), pwn->getstatus(), pwn->getmove_count() ,pwn->getindice(),'q', pwn->getnumber());
			delete pwn;
			pwn = new queen(extra);
			};
			break;

			case 'b':
			{bishop extra(pwn->getcolor(), pwn->getline(), pwn->getcolumn(), pwn->getstatus(), pwn->getmove_count(),pwn->getindice(),'b', pwn->getnumber());
			delete pwn;
			pwn = new bishop(extra);
			};
			break;
			}
		}
	}
void piece ::  kill(piece*** board) {
	status = dead;
	line = -1;
	column = 10;
 }
void piece :: move(int newline, int newcolumn, piece***& board) {
	if (board[newline][newcolumn] != nullptr) {
		board[newline][newcolumn]->kill(board);
	}
	board[newline][newcolumn] = board[line][column];
	board[line][column] = nullptr;
	if (prom == 'u') {
		if (newcolumn == column + 2) {
			board[line][column + 1] = board[line][column + 3];
			board[line][column + 3] = nullptr;
		}
		else if(newcolumn==column-2) {
			board[line][column -1] = board[line][column -4];
			board[line][column -4] = nullptr;
		}
	}
	line = newline;
	column = newcolumn;
	move_count++;
}
bool in_check_mate(piece* kng, piece*** teams, piece*** board) {
	int opteam = (kng->getcolor() + 1) % 2;
	int i, j, k;
	if (in_check(kng, teams[opteam], board) == false)return false;
	for (i = 0; i < 16; i++) {
		if (teams[kng->getcolor()][i]->getstatus() == dead)continue;
		for (j = 0; j < 8; j++) {
			for (k = 0; k < 8; k++) {
				
				if ((teams[kng->getcolor()][i]->valid_move(j, k, board) == 1) && (teams[kng->getcolor()][i]->check_validity(j, k, board, teams) == 1))
				{
					
					return false;
				}

			}
		}

	}
	std::cout << "checkmate!" << std::endl;
	return true;
}
bool in_stale_mate(piece* kng, piece*** teams, piece*** board) {
	int opteam = (kng->getcolor() + 1) % 2;
	int i, j, k;
	if (in_check(kng, teams[opteam], board) == true)return false;
	for (i = 0; i < 16; i++) {
		if (teams[kng->getcolor()][i]->getstatus() == dead)continue;
		for (j = 0; j < 8; j++) {
			for (k = 0; k < 8; k++) {

				if ((teams[kng->getcolor()][i]->valid_move(j, k, board) == 1)  && (teams[kng->getcolor()][i]->check_validity(j, k, board, teams) == 1))
					return false;

			}
		}
		
	}
	std::cout << "stalemate!" << std::endl;
	return true;
}
 };
