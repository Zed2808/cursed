#ifdef __MINGW32__
#include <curses.h>
#endif

#ifdef __linux__
#include <ncurses.h>
#endif

#include "tile.hpp"

#include <string>

Tile::Tile() {
    name = "empty";
    symbol = '.';
    color_pair = 4;
}

Grass::Grass() {
    name = "grass";
    symbol = '.';
    color_pair = 3;
}

Stone::Stone() {
    name = "stone";
    symbol = '.';
    color_pair = 4;
}
