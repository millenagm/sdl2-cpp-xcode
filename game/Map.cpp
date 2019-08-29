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
    else if (key == "x")
        return { 2, 2 };
    else if (key == "M")
        return { 0, 8 };
    else if (key == "-")
        return { 2, 0 };
    else if (key == "_")
        return { 1, 4 };
    else if (key == "-|")
        return { 5, 2 };
    else if (key == "|-")
        return { 0, 2 };
    else if (key == "_|") //bottom right corner
        return { 5, 4 };
    else if (key == "|_") //bottom left corner
        return { 0, 4 };
    else if (key == "'|") //top right corner
        return { 5, 0 };
    else if (key == "|'") //top left corner
        return { 0, 0 };
    return { };
}

Sprite *sprite16x16ForKey(string key, int x, int y, int size, SDL_Renderer *renderer) {
    if (key == " ") return NULL;

    int th = 16, tw = 16;
    int divider = 1;
    Tile t = tileForKey(key);
    SDL_Rect ipos = { x * size, y * size, size, size };
    SDL_Rect isrc = { t.x * tw +divider , t.y * th + divider , tw - divider, th - divider};
    
    return new Sprite("assets/dungeon.png", ipos, isrc, renderer);
}

Sprite *sprite16x16ForMap(string map[10][10], int x, int y, int size, SDL_Renderer *renderer) {
    return sprite16x16ForKey(map[y][x], x, y, size, renderer);
}

void addSpriteToVector(Sprite *sprite, vector <Sprite *> *vec) {
    if (sprite == NULL) return;
    vec->push_back(sprite);
}

Map::Map(int _size, SDL_Renderer *_renderer) {
    w = 10;
    h = 10;
    size = _size;
    renderer = _renderer;
    
    string litems[10][10] = {
        { " ", " ", " ", " ", " ", " ", " ", " ", " ", " " },
        
        { " ", " ", "K", " ", " ", " ", " ", " ", " ", " " },
        
        { " ", " ", " ", " ", " ", " ", " ", " ", " ", " " },
        
        { " ", " ", " ", " ", " ", " ", " ", " ", " ", " " },
        
        { " ", " ", " ", " ", " ", " ", " ", " ", " ", " " },
        
        { " ", " ", " ", " ", " ", " ", " ", " ", " ", " " },
        
        { " ", " ", "J", " ", " ", " ", " ", " ", " ", " " },
        
        { " ", " ", " ", " ", " ", "J", " ", " ", " ", " " },
        
        { " ", " ", " ", " ", " ", " ", " ", " ", " ", " " },
        
        { " ", " ", " ", " ", " ", " ", " ", " ", " ", " " }
    };
    
    string lwalls[10][10] = {
        { "|'", "-", "-", "-", "-", "-", "-", "-", "-", "-" },
        
        { "|-", " ", "M", " ", " ", " ", " ", " ", " ", " " },
        
        { "|-", " ", " ", " ", " ", " ", " ", "_", "_", "-|" },
        
        { "|-", " ", " ", " ", " ", " ", " ", " ", " ", "-|" },
        
        { "|-", " ", " ", " ", " ", " ", " ", " ", " ", "-|" },
        
        { "|-", " ", " ", " ", " ", " ", " ", " ", " ", "-|" },
        
        { "|-", " ", "M", " ", " ", " ", " ", " ", " ", "-|" },
        
        { "|-", " ", " ", " ", " ", " ", " ", " ", " ", "-|" },
        
        { "|-", " ", " ", " ", " ", " ", " ", "M", " ", "-|" },
        
        { "|_", "_", "_", "_", "_", "_", "_", "_", "_", "_|" }
    };
    
    for (int x = 0; x < w; x++) {
        for (int y = 0; y < h; y++) {
            addSpriteToVector(sprite16x16ForMap(litems, x, y, size, renderer), &items);
            addSpriteToVector(sprite16x16ForMap(lwalls, x, y, size, renderer), &walls);
            addSpriteToVector(sprite16x16ForKey("x", x, y, size, renderer), &grid);
        }
    }
}

void Map::exec() {
    for (Sprite* g : grid)
        g->exec();
    
    for (Sprite* i : items)
        i->exec();
    
    for (Sprite* w : walls)
        w->exec();
}
