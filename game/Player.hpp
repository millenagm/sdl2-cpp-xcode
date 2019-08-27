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

#include <SDL2_image/SDL_image.h>
#include <iostream>

enum Direction {
    direction_up = 0,
    direction_down = 2,
    direction_left = 1,
    direction_right = 3,
};

class Player {
protected:
    SDL_Renderer *renderer;
private:
    float speed;
    Direction direction;
    SDL_Texture *texture;
    SDL_Surface *image;
    const char *name;
    bool moving;
public:
    Player(const char *_name, SDL_Renderer *_renderer);
    void move(SDL_Event event);
    SDL_Rect pos;
    void exec();
    void start();
    void end();
};

#endif /* Player_hpp */
