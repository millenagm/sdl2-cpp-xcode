//
//  Grid.cpp
//  game
//
//  Created by Millena Galvão on 29/08/2019.
//  Copyright © 2019 millena. All rights reserved.
//

#include "Sprite.hpp"

Sprite::Sprite(const char *sprite, SDL_Rect _pos, SDL_Renderer *_renderer) {
    renderer = _renderer;
    image = IMG_Load(sprite);
    pos = _pos;
    texture = SDL_CreateTextureFromSurface(renderer, image);
}

Sprite::Sprite(const char *sprite, SDL_Rect _pos, SDL_Rect _src, SDL_Renderer *_renderer) {
    renderer = _renderer;
    image = IMG_Load(sprite);
    pos = _pos;
    src = _src;
    texture = SDL_CreateTextureFromSurface(renderer, image);
}

void Sprite::start() {
    
}

void Sprite::exec() {
    SDL_RenderCopyEx(renderer, texture, &src, &pos, 0, NULL, SDL_FLIP_NONE);
}

void Sprite::end() {
    SDL_DestroyTexture(texture);
}
