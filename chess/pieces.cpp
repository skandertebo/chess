#include "pieces.h"
namespace piece {
bool rook :: valid_move(int newline , char newcolumn , piece***board){

}
bool pawn :: valid_move(int newline , char newcolumn , piece***board){

}
bool bishop :: valid_move(int newline , char newcolumn , piece***board){

}
bool queen :: valid_move(int newline , char newcolumn , piece***board){

}
bool king :: valid_move(int newline , char newcolumn , piece***board){

}
bool knight :: valid_move(int newline , char newcolumn , piece***board){

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
