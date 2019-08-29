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

const Vector2D vector_left  = Vector2D(-1,  0);
const Vector2D vector_right = Vector2D( 1,  0);
const Vector2D vector_up    = Vector2D( 0, -1);
const Vector2D vector_down  = Vector2D( 0,  1);
const Vector2D vector_zero  = Vector2D( 0,  0);

Player::Player(const char *_name, SDL_Renderer *_renderer, int _size) {
    name = _name;
    renderer = _renderer;
    speed = 0.2f;
    image = IMG_Load("link.png");
    texture = SDL_CreateTextureFromSurface(renderer, image);
    direction = vector_zero;
    
    float scale = 1.0f;
    w = image->w / num_sprites_width * scale;
    h = image->h / num_sprites_height * scale;
    
    w = _size;
    h = _size;
    
    pos = { w, h, w, h };
    destinationPoint = Vector2D(w, h);
}

void Player::moveTo(SDL_Point point) {
    int mx = point.x / w * w;
    int my = point.y / h * h;
    destinationPoint = Vector2D(mx, my);
}

void Player::start() {
    
}

Direction spritedirection(Vector2D dir) {
    if (dir == vector_down)
        return direction_down;
    else if (dir == vector_up)
        return direction_up;
    else if (dir == vector_left)
        return direction_left;
    else
        return direction_right;
}

void Player::cancelMovement(SDL_Rect collider) {
    int nx = collider.x,
        ny = collider.y;
    
    Vector2D diffVector = Vector2D(nx , ny) - Vector2D(pos.x , pos.y);
    
    if (collider.x != pos.x) {
        direction = diffVector.x > 0 ? vector_right : vector_left;
    } else if (collider.y != pos.y) {
        direction = diffVector.y > 0 ? vector_down : vector_up;
    }
    
    spriteDirection = spritedirection(direction);
    
    switch (spriteDirection) {
        case direction_right: nx -= w; break;
        case direction_down:  ny -= h; break;
        case direction_left:  nx += w; break;
        case direction_up:    ny += h; break;
    }
    moveTo({ nx, ny });
}

void Player::exec(float delta) {
    // TODO:
    // AStart Pathfinding
    Vector2D diffVector = destinationPoint - Vector2D(pos.x , pos.y);
    
    if (destinationPoint.x != pos.x) {
        direction = diffVector.x > 0 ? vector_right : vector_left;
    } else if (destinationPoint.y != pos.y) {
        direction = diffVector.y > 0 ? vector_down : vector_up;
    } else {
        direction = vector_zero;
    }
    // AStart Pathfinding

    pos.x += speed * direction.x * delta;
    pos.y += speed * direction.y * delta;
    
    Uint32 sprite = 0;
    
    if (direction.isZero() == false) {
        Uint32 seconds = SDL_GetTicks() / (1000 / (num_sprites_width * 1));
        sprite = seconds % num_sprites_width;
    }
    
    spriteDirection = spritedirection(direction);
    
    SDL_Rect src = { static_cast<int>
        (sprite * image->w / num_sprites_width),
        image->h / num_sprites_height * spriteDirection,
        image->w / num_sprites_width,
        image->h / num_sprites_height };
    
    SDL_RenderCopyEx(renderer, texture, &src, &pos, NULL, NULL, SDL_FLIP_NONE);
}

void Player::end() {
    SDL_DestroyTexture(texture);
}
