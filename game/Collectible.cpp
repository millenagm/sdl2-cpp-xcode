//
//  Collectible.cpp
//  game
//
//  Created by Millena Galvão on 27/08/2019.
//  Copyright © 2019 millena. All rights reserved.
//

#include "Collectible.hpp"

Collectible::Collectible(const char *sprite, SDL_Renderer *_renderer, int x, int y) {
    renderer = _renderer;
    image = IMG_Load(sprite);
    texture = SDL_CreateTextureFromSurface(renderer, image);
    
    float scale = 0.3f;
    pos = { x, y,
        static_cast<int>(image->w / 1 * scale),
        static_cast<int>(image->h / 1 * scale)
    };
    
    angle = rand() % 360;
}

void Collectible::start() {
    
}

void Collectible::exec() {
    angle++;
    SDL_RenderCopyEx(renderer, texture, NULL, &pos, angle, NULL, SDL_FLIP_NONE);
}

void Collectible::end() {
    SDL_DestroyTexture(texture);
}
