//
//  GameSDL.cpp
//  game
//
//  Created by Millena Galvão on 26/08/2019.
//  Copyright © 2019 millena. All rights reserved.
//

#include "GameSDL.hpp"

GameSDL::GameSDL(int width, int height) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    
    window = SDL_CreateWindow("Game",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              width,
                              height,
                              SDL_WINDOW_OPENGL);
    
    if (window == nullptr) {
        SDL_Log("window == nullptr %s", SDL_GetError());
        _isRunning = false;
        return;
    }
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    if (renderer == nullptr) {
        SDL_Log("renderer == nullptr %s", SDL_GetError());
        _isRunning = false;
    }
}

bool GameSDL::isRunning() {
    return _isRunning;
}

void GameSDL::handleEvent(SDL_Event event) {
    switch(event.type) {
        case SDL_QUIT:
            _isRunning = false;
            break;
        default:
            player->move(event);
            break;
    }
}

void GameSDL::start() {
    player = new Player("link", renderer);
    player->start();
    _isRunning = true;
}

void GameSDL::exec() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    
    player->exec();
    
    SDL_Event event;
    
    if (SDL_PollEvent(&event)){
        handleEvent(event);
    }
    
    SDL_RenderPresent(renderer);
}


void GameSDL::end() {
    player->end();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}
