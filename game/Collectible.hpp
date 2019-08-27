//
//  Collectible.hpp
//  game
//
//  Created by Millena Galvão on 27/08/2019.
//  Copyright © 2019 millena. All rights reserved.
//

#ifndef Collectible_hpp
#define Collectible_hpp

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#include <SDL2/SDL.h>
#pragma clang diagnostic pop

#include <SDL2_image/SDL_image.h>
#include <iostream>
#include <stdio.h>

class Collectible {
protected:
    SDL_Renderer *renderer;
private:
    SDL_Rect pos;
    SDL_Texture *texture;
    SDL_Surface *image;
    float angle;
public:
    Collectible(const char *sprite, SDL_Renderer *_renderer, int x, int y);
    
    void exec();
    void start();
    void end();
};

#endif /* Collectible_hpp */
