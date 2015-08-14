#ifdef __MINGW32__
#include <curses.h>
#endif

#ifdef __linux__
#include <ncurses.h>
#endif

#include <string>
#include "tile.hpp"

Tile::Tile() {
    id = 0x00;
    name = "empty";
    symbol = ' ';
    color_pair = 4;
    walkable = true;
}

Grass::Grass() {
    id = 0x01;
    name = "grass";
    symbol = '.';
    color_pair = 3;
    walkable = true;
}

Stone::Stone() {
    id = 0x02;
    name = "stone";
    symbol = '.';
    color_pair = 4;
    walkable = true;
}

Wall::Wall() {
    id = 0x03;
    name = "wall";
    symbol = '#';
    color_pair = 2;
    walkable = false;
}

Tile get_tile_from_id(unsigned char id) {
    switch (id) {
        case 0x00:
            return Tile();
            break;
        case 0x01:
            return Grass();
            break;
        case 0x02:
            return Stone();
            break;
        case 0x03:
            return Wall();
            break;
        default:
            return Tile();
    }
}
