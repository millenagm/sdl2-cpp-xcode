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

struct Clock
{
    uint32_t last_tick_time = 0;
    uint32_t delta = 0;
    
    void tick()
    {
        uint32_t tick_time = SDL_GetTicks();
        delta = tick_time - last_tick_time;
        last_tick_time = tick_time;
    }
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
    vector<Collectible *> walls;
    Collectible *p;
    Clock clock;
    void checkCollisions();
    bool isHittingWall;
public:
    GameSDL(int, int);
    bool isRunning();
    void exec();
    void start();
    void end();
};

#endif /* GameSDL_hpp */
