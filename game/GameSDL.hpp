//
//  GameSDL.hpp
//  game
//
//  Created by Millena Galvão on 26/08/2019.
//  Copyright © 2019 millena. All rights reserved.
//

#ifndef GameSDL_hpp
#define GameSDL_hpp

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#include <SDL2/SDL.h>
#pragma clang diagnostic pop

#include <iostream>
#include <stdio.h>
#include <vector>

#include "Player.hpp"
#include "Collectible.hpp"

using namespace std;

enum GameState
{
    Idle,
};

class GameSDL {
private:
    int width, height;
    Player *player;
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool _isRunning;
    void handleEvent(SDL_Event);
    vector<Collectible *> collectibles;
    Collectible *p;
public:
    GameSDL(int, int);
    bool isRunning();
    void exec();
    void start();
    void end();
};

#endif /* GameSDL_hpp */
