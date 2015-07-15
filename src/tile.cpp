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
    fgcolor = COLOR_WHITE;
    bgcolor = COLOR_BLACK;
}

Grass::Grass() {
    name = "grass";
    symbol = '.';
    fgcolor = COLOR_GREEN;
    bgcolor = COLOR_BLACK;
}

Stone::Stone() {
    name = "stone";
    symbol = '.';
    fgcolor = COLOR_WHITE;
    bgcolor = COLOR_BLACK;
}
