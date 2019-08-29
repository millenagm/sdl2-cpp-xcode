//
//  Sprite.hpp
//  game
//
//  Created by Millena Galvão on 29/08/2019.
//  Copyright © 2019 millena. All rights reserved.
//

#ifndef Sprite_hpp
#define Sprite_hpp

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#include <SDL2/SDL.h>
#pragma clang diagnostic pop

#include <SDL2_image/SDL_image.h>
#include <iostream>
#include <stdio.h>
#include <vector>

class Sprite {
private:
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Surface *image;
    SDL_Rect src;
public:
    Sprite(const char *sprite, SDL_Rect _pos, SDL_Renderer *_renderer);
    Sprite(const char *sprite, SDL_Rect _pos, SDL_Rect _src, SDL_Renderer *_renderer);
    void exec();
    void start();
    void end();
    
    SDL_Rect pos;
};

#endif /* Sprite_hpp */
