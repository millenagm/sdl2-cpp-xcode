//
//  Player.cpp
//  game
//
//  Created by Millena Galvão on 27/08/2019.
//  Copyright © 2019 millena. All rights reserved.
//

#include "Player.hpp"


Player::Player(const char *_name, const char *_sprite) {
    name = _name;
    sprite = _sprite;
    
    printf("new player: %s", name);
}

void Player::move(SDL_Keycode keyCode) {
    switch(keyCode){
        case SDLK_LEFT:
            printf("%s is moving left\n", name);
            break;
        case SDLK_RIGHT:
            printf("%s is moving right\n", name);
            break;
        case SDLK_UP:
            printf("%s is moving up\n", name);
            break;
        case SDLK_DOWN:
            printf("%s is moving down\n", name);
            break;
        default:
            printf("%s does not move %s\n", SDL_GetKeyName(keyCode), name);
            break;
    }
}
