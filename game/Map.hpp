//
//  Map.hpp
//  game
//
//  Created by Millena Galvão on 28/08/2019.
//  Copyright © 2019 millena. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#include <SDL2/SDL.h>
#pragma clang diagnostic pop

#include <iostream>
#include <stdio.h>
#include <vector>

#include "Sprite.hpp"

using namespace std;

class Map {
private:
    int w, h, size;
    vector <Sprite *> grid;
    vector <Sprite *> items;
    SDL_Renderer *renderer;
public:
    Map(int _size, SDL_Renderer *_renderer);
    void exec();
    inline vector <Sprite *> getCollectibles() { return items; }
};

#endif /* Map_hpp */
