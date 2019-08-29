//
//  Map.cpp
//  game
//
//  Created by Millena Galvão on 28/08/2019.
//  Copyright © 2019 millena. All rights reserved.
//

#include "Map.hpp"

struct Tile {
    int x, y;
};

Tile tileForKey(string key) {
    if (key == "K")
        return { 9, 9 };
    else if (key == "J")
        return { 8, 9 };
    return { };
}

Map::Map(int _size, SDL_Renderer *_renderer) {
    w = 10;
    h = 10;
    size = _size;
    renderer = _renderer;
    
    int tw = 160 / 10;
    int th = 160 / 10;
    
    string map[10][10] = {
        { " ", " ", " ", " ", " ", " ", " ", " ", " ", " " },
        
        { " ", " ", "K", " ", " ", " ", " ", " ", " ", " " },
        
        { " ", " ", " ", " ", " ", " ", " ", " ", " ", " " },
        
        { " ", " ", " ", " ", " ", " ", " ", " ", "K", " " },
        
        { " ", " ", " ", " ", " ", " ", " ", " ", " ", " " },
        
        { " ", " ", " ", " ", " ", " ", " ", " ", " ", " " },
        
        { " ", " ", "J", " ", " ", " ", " ", " ", " ", " " },
        
        { " ", " ", " ", " ", " ", "J", " ", " ", " ", " " },
        
        { " ", " ", " ", " ", " ", " ", " ", " ", " ", " " },
        
        { " ", " ", " ", " ", " ", " ", " ", " ", " ", " " }
    };
    
    for (int x = 0; x < w; x++) {
        for (int y = 0; y < h; y++) {
            string item = map[y][x];
            
            Tile t = tileForKey(item);
            SDL_Rect ipos = { x * size + size / 4, y * size + size / 4, size / 2, size / 2 };
            SDL_Rect isrc = { t.x * tw , t.y * th , tw, th };
            
            if (item != " ") {
                items.push_back(new Sprite("dungeon.png", ipos, isrc, renderer));
            }
        }
    }
    
  
    
    for (int x = 0; x < w; x++) {
        for (int y = 0; y < h; y++) {
            int lx, ly;

            if (x == 0) {
                lx = 0;
            } else if (x == w - 1) {
                lx = 5;
            } else {
                lx = 2;
            }

            if (y == 0) {
                ly = 0;
            } else if (y == h - 1) {
                ly = 4;
            } else {
                ly = 2;
            }

            int divider = 0;
            SDL_Rect pos = { x * size, y * size, size, size };
            SDL_Rect src = { lx * tw + divider , ly * th + divider , tw - divider, th - divider };
            grid.push_back(new Sprite("dungeon.png", pos, src, renderer));
        }
    }
}

void Map::exec() {
    for (Sprite* g : grid)
        g->exec();
    
    for (Sprite* i : items)
        i->exec();
}
