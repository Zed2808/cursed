#ifdef __MINGW32__
#include <curses.h>
#endif

#ifdef __linux__
#include <ncurses.h>
#endif

#include <string>
#include "tile.hpp"

Tile::Tile() {
    id = 0;
    name = "empty";
    symbol = ' ';
    color_pair = 4;
    walkable = true;
}

Grass::Grass() {
    id = 1;
    name = "grass";
    symbol = '.';
    color_pair = 3;
    walkable = true;
}

Stone::Stone() {
    id = 2;
    name = "stone";
    symbol = '.';
    color_pair = 4;
    walkable = true;
}

Wall::Wall() {
    id = 3;
    name = "wall";
    symbol = '#';
    color_pair = 2;
    walkable = false;
}

Tile get_tile_from_id(int id) {
    switch (id) {
        case 0:
            return Tile();
            break;
        case 1:
            return Grass();
            break;
        case 2:
            return Stone();
            break;
        case 3:
            return Wall();
            break;
        default:
            return Tile();
    }
}
