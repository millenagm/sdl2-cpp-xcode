//
//  Player.hpp
//  game
//
//  Created by Millena Galvão on 27/08/2019.
//  Copyright © 2019 millena. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#include <SDL2/SDL.h>
#pragma clang diagnostic pop

#include <iostream>

class Player {
private:
    const char *name, *sprite;
public:
    Player(const char *_name, const char *_sprite);
    void move(SDL_Keycode keyCode);
};

#endif /* Player_hpp */
