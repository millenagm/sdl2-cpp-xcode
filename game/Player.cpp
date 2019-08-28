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
    speed = 0.2f;
    image = IMG_Load("link.png");
    texture = SDL_CreateTextureFromSurface(renderer, image);
    direction = direction_down;
    
    float scale = 1.0f;
    float w = image->w / num_sprites_width * scale;
    float h = image->h / num_sprites_height * scale;
    pos = { 0, 0,
        static_cast<int>(w),
        static_cast<int>(h)
    };
    
    destination = Vector2D(0, 0);
}

void Player::moveTo(SDL_Point point) {
    destCopy = Vector2D(point.x, point.y);
    destination = destCopy - Vector2D(pos.x , pos.y);
    destination.normalize();
    moving = true;
}

void Player::move(SDL_Event event) {
    switch(event.type){
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_LEFT:     direction = direction_left;  destination = Vector2D(-1,  0);   moving = true; break;
                case SDLK_RIGHT:    direction = direction_right; destination = Vector2D( 1,  0);   moving = true; break;
                case SDLK_UP:       direction = direction_up;    destination = Vector2D( 0, -1);   moving = true; break;
                case SDLK_DOWN:     direction = direction_down;  destination = Vector2D( 0,  1);   moving = true; break;
                default: break;
            }
            break;
        case SDL_KEYUP:
            moving = false; break;
        default: break;
    }
}

void Player::start() {
    
}

void Player::exec(float delta) {
    Uint32 sprite = 0;
    
    if (moving) {
        Uint32 seconds = SDL_GetTicks() / (1000 / (num_sprites_width * 1));
        sprite = seconds % num_sprites_width;
        
        pos.x += speed * destination.x * delta;
        pos.y += speed * destination.y * delta;
    }
    
    SDL_Rect src = { static_cast<int>
        (sprite *   image->w / num_sprites_width),
                    image->h / num_sprites_height * direction,
                    image->w / num_sprites_width,
                    image->h / num_sprites_height };
    
    SDL_RenderCopyEx(renderer, texture, &src, &pos, NULL, NULL, SDL_FLIP_NONE);
}

void Player::end() {
    SDL_DestroyTexture(texture);
}
