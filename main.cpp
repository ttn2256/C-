
#include <iostream>
#include "Player.h"
#include "LoShuSquare.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Welcome to Lo Shu Square Game!\n";

    LoShuSquare game;
    Player newPlayer(game);
    
    return 0;

}

