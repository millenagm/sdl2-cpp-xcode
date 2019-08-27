//
//  Player.cpp
//  game
//
//  Created by Millena Galvão on 27/08/2019.
//  Copyright © 2019 millena. All rights reserved.
//

#include "Player.hpp"

const int num_sprites_width = 9;
const int num_sprites_height = 4;

Player::Player(const char *_name, SDL_Renderer *_renderer) {
    name = _name;
    renderer = _renderer;
    speed = 10.f;
    image = IMG_Load("link.png");
    texture = SDL_CreateTextureFromSurface(renderer, image);
    direction = direction_down;
    
    float scale = 1.0f;
    pos = { 0, 0,
        static_cast<int>(image->w / num_sprites_width * scale),
        static_cast<int>(image->h / num_sprites_height * scale)
    };
}

void Player::move(SDL_Event event) {
    switch(event.type){
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_LEFT:     pos.x -= speed; direction = direction_left;     moving = true; break;
                case SDLK_RIGHT:    pos.x += speed; direction = direction_right;    moving = true; break;
                case SDLK_UP:       pos.y -= speed; direction = direction_up;       moving = true; break;
                case SDLK_DOWN:     pos.y += speed; direction = direction_down;     moving = true; break;
                default:
                    printf("%s not handled for Player", SDL_GetKeyName(event.key.keysym.sym));
                    break;
            }
            break;
        default: moving = false; break;
    }
}

void Player::start() {
    
}

void Player::exec() {
    Uint32 sprite = 0;
    
    if (moving) {
        Uint32 seconds = SDL_GetTicks() / (1000 / (num_sprites_width * 1));
        sprite = seconds % num_sprites_width;
    }
    
    SDL_Rect src = { static_cast<int>
        (sprite *   image->w / num_sprites_width),
                    image->h / num_sprites_height * direction,
                    image->w / num_sprites_width,
                    image->h / num_sprites_height };
    
    SDL_RenderCopy(renderer, texture, &src, &pos);
}

void Player::end() {
    SDL_DestroyTexture(texture);
}
