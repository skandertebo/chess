#include "pieces.h"
namespace piece {
bool rook :: valid_move(int newline , char newcolumn , piece***board){
	return 0;
}
bool pawn :: valid_move(int newline , char newcolumn , piece***board){
	return 0;
}
bool bishop :: valid_move(int newline , char newcolumn , piece***board){
	return 0;
}
bool queen :: valid_move(int newline , char newcolumn , piece***board){
	return 0;
}
bool king :: valid_move(int newline , char newcolumn , piece***board){
	return 0;
}
bool knight :: valid_move(int newline , char newcolumn , piece***board){
	return 0;
}

void promote(piece* pwn , char prom){
switch(prom){
case 'r' :
rook rkextra(pwn->getcolor() , pwn->getline(),  pwn->getcolumn() , pwn->getstatus()); 
delete pwn ;
*pwn = rook(rkextra);


}


}


};
