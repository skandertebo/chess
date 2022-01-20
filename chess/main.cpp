#include <iostream>
#include "pieces.h"

int main(){
    piece :: rook e1(0,0,'c',false);
    std::cout << e1.valid_move(4 , 'c' ,NULL);

    
}