#pragma once
#include <iostream>
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

namespace piece {

class piece {

protected : 

bool status;
int line ;
char column ;
int color ;

public : 
static const char prom;
virtual bool valid_move(int newline , int newcolumn , piece*** board)=0; 
// note that valid move only checks the piece's move validity without looking into exposing the king to a check 
// for the piece to have an actual valid move it should pass the valid_move method and the check situation function
piece(int color , int line , int column , bool status):color(color) , status(status) , line(line) , column(column) {};
~piece(){}
piece(const piece& pce) : color(pce.color) , line(pce.line) , column(pce.column) , status(pce.status) {};
void move(int newline , int newcolumn , piece***board);
void kill();
bool getstatus(){return status;}
int  getcolor(){return color;}
int getline(){return line;}
int getcolumn(){return column;}
void setcolor(int color){this->color = color;}
void setline(int line){this->line = line;}
void setcolumn(int column){this->column = column;}
void setstatus(bool status){this->status = status;}


};

class pawn : public piece{
public:
bool valid_move(int newline , int newcolumn , piece*** board);
pawn(int color, int line, int column, bool status) : piece(color, line, column, status) {};
pawn(const pawn& pwn) : piece(pwn){};
static const char prom = 'p';
};

class rook : public piece{
public:
bool valid_move(int newline , int newcolumn , piece*** board);
rook(int color , int line , int column , bool status) : piece(color , line , column , status){};
static const char prom = 'r' ;
rook(const rook& rk) : piece(rk){};
};

class queen : public piece{
public:
bool valid_move(int newline , int newcolumn , piece*** board);
queen(int color , int line , int column , bool status) : piece(color , line , column , status){};
static const char prom = 'q' ;
queen(const queen& q) : piece(q) {};
};

class knight : public piece{
public:
bool valid_move(int newline , int newcolumn , piece*** board);
knight(int color , int line , int column , bool status) : piece(color , line , column , status){};
static const char prom = 'k' ;
knight(const knight& k) : piece(k) {};
};

class bishop : public piece{
public:
bool valid_move(int newline , int newcolumn , piece*** board);
bishop(int color , int line , int column , bool status) : piece(color , line , column , status){};
static const char prom = 'b' ;
bishop(const rook& bi) : piece(bi) {};
};

class king : public piece{
public:
bool valid_move(int newline , int newcolumn , piece*** board);
king(int color , int line , int column , bool status) : piece(color , line , column , status){};
bool in_check();
bool in_check_mate();
};
void promote(piece* pwn , char prom );



};
