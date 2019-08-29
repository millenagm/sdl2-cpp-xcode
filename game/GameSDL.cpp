//
//  GameSDL.cpp
//  game
//
//  Created by Millena Galvão on 26/08/2019.
//  Copyright © 2019 millena. All rights reserved.
//

#include "GameSDL.hpp"

int tileSize = 64;

GameSDL::GameSDL(int _width, int _height) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    width = _width;
    height = _height;
    
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
    if (event.type == SDL_MOUSEBUTTONDOWN) {
        SDL_Point point = { event.button.x, event.button.y };
        player->moveTo(point);
    } else if (event.type == SDL_QUIT) {
        _isRunning = false;
    }
}

void GameSDL::start() {
    player = new Player("link", renderer, tileSize);
    map = new Map(tileSize, renderer);
    player->start();
    _isRunning = true;
}

void GameSDL::exec() {
    clock.tick();
    
    SDL_Event event;
    if (SDL_PollEvent(&event)){  handleEvent(event); }
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    
    checkCollisions();
    map->exec();
    player->exec(clock.delta);
    
    SDL_RenderPresent(renderer);
}

void GameSDL::checkCollisions() {
    for (Sprite* col : map->getWalls())
        if (SDL_HasIntersection(&player->pos, &col->pos))
            player->cancelMovement(col->pos);
            
    for (Sprite* col :  map->getCollectibles())
        if (SDL_HasIntersection(&player->pos, &col->pos))
            col->end();
}


void GameSDL::end() {
    player->end();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}
