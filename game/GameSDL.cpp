//
//  GameSDL.cpp
//  game
//
//  Created by Millena Galvão on 26/08/2019.
//  Copyright © 2019 millena. All rights reserved.
//

#include "GameSDL.hpp"

GameSDL::GameSDL(int width, int height) {
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
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
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
        case SDL_KEYDOWN:
            printf("%s\n", SDL_GetKeyName(event.key.keysym.sym));
            break;
        default:
            break;
    }
}

void GameSDL::start() {
    _isRunning = true;
}

void GameSDL::exec() {
    SDL_Event event;
    
    if (SDL_PollEvent(&event)){
        handleEvent(event);
    }
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}


void GameSDL::end() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
