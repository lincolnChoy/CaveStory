#include "../headers/tile.h"
#include "../headers/graphics.h"

#include <SDL2/SDL.h>

Tile::Tile() {}

Tile::Tile(SDL_Texture* tileset, Vector2 size, Vector2 tilesetPosition, Vector2 position) :
    _tileset(tileset),
    _size(size),
    _tilesetPosition(tilesetPosition),
    _position(Vector2(position.x * globals::SRPITE_SCALE, position.y * globals::SRPITE_SCALE))
{}

void Tile::update(int elapsedTime) {}

void Tile::draw(Graphics &graphics) {
    SDL_Rect destRect = { this->_position.x, this->_position.y, (int)(this->_size.x * globals::SRPITE_SCALE), (int)(this->_size.y * globals::SRPITE_SCALE) };
    SDL_Rect sourceRect = { this->_tilesetPosition.x, this->_tilesetPosition.y, this->_size.x, this->_size.y };

    graphics.blitSurface(this->_tileset, &sourceRect, &destRect);
}