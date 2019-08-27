//
//  main.cpp
//  game
//
//  Created by Millena Galvão on 23/08/2019.
//  Copyright © 2019 millena. All rights reserved.
//


#include <iostream>
#include <stdio.h>

#include "GameSDL.hpp"

int main(int argc, const char * argv[]) {
    GameSDL *game = new GameSDL(640, 480);
    game->start();
    
    while (game->isRunning()) {
        game->exec();
    }
    
    game->end();
    
    return 0;
}
