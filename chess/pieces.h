#pragma once
#include <iostream>
#define COMMON_CHECK if ((newline > 7) || (newcolumn > 7)) return false; if ((board[newline][newcolumn] != nullptr) && (board[newline][newcolumn]->getcolor() == color))return false;
// to implement letters in column index
const int a = 0 ;
const int b = 1 ;
const int c = 2 ;
const int d = 3 ;
const int e = 4 ;
const int f = 5 ;
const int g = 6 ;
const int h = 7;

const int alive = 0 ;
const int dead = 1 ;
const int white = 0 ;
const int black = 1 ;
// NB : in an array of pieces that represents a team : the king should be set to the index of 0  
namespace piece {

class piece {

protected : 

bool status;
int move_count;
int line ;
char column ;
int color ;
char prom; //to identify the piece type when promoting a pawn
public : 
char getprom() { return prom; }
virtual bool valid_move(int newline , int newcolumn , piece*** board)=0; 
// note that valid move only checks the piece's move validity without looking into exposing the king to a check 
// for the piece to have an actual valid move it should pass the valid_move method and the check situation function
piece(int color , int line , int column , bool status , int move_count ):color(color) , status(status) , line(line) , column(column) , move_count(move_count) {};
~piece(){}
piece(const piece& pce) : color(pce.color) , line(pce.line) , column(pce.column) , status(pce.status) , prom(pce.prom) , move_count(pce.move_count) {};
void move(int newline , int newcolumn , piece***board);
void kill(piece*** board);
bool getstatus(){return status;}
int  getcolor(){return color;}
int getline(){return line;}
int getcolumn(){return column;}
int getmove_count() { return move_count; }
void setcolor(int color){this->color = color;}
void setline(int line){this->line = line;}
void setcolumn(int column){this->column = column;}
void setstatus(bool status){this->status = status;}
bool check_validity(int newline, int newcolumn, piece*** board, piece** teams);


};

class pawn : public piece{
public:
bool valid_move(int newline , int newcolumn , piece*** board);
pawn(int color, int line, int column, bool status , int move_count) : piece(color, line, column, status, move_count ) { prom = 'p'; };
pawn(const pawn& pwn) : piece(pwn){};

};

class rook : public piece{
public:
bool valid_move(int newline , int newcolumn , piece*** board);
rook(int color , int line , int column , bool status, int move_count) : piece(color , line , column , status , move_count){ prom = 'r'; };

rook(const rook& rk) : piece(rk){};
};

class queen : public piece{
public:
bool valid_move(int newline , int newcolumn , piece*** board);
queen(int color , int line , int column , bool status, int move_count) : piece(color , line , column , status, move_count){ prom = 'q'; };
queen(const queen& q) : piece(q) {};
};

class knight : public piece{
public:
bool valid_move(int newline , int newcolumn , piece*** board);
knight(int color , int line , int column , bool status, int move_count) : piece(color , line , column , status, move_count){ prom = 'k'; };
knight(const knight& k) : piece(k) {};
};

class bishop : public piece{
public:
bool valid_move(int newline , int newcolumn , piece*** board);
bishop(int color , int line , int column , bool status, int move_count) : piece(color , line , column , status, move_count){ prom = 'b'; };
bishop(const rook& bi) : piece(bi) {};
};

class king : public piece{
public:
bool valid_move(int newline , int newcolumn , piece*** board);
king(int color, int line, int column, bool status, int move_count) : piece(color, line, column, status, move_count) { prom = 'k'; };

};

void promote(piece* pwn , char prom );
bool in_check(king& kng , piece* team , piece *** board);
bool in_check_mate(king& kng , piece** teams , piece *** board);
bool in_stale_mate(king& kng, piece** teams, piece*** board);


};
