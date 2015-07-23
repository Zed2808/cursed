#ifndef MAPS_H
#define MAPS_H

#include "tile.hpp"
#include "character.hpp"

// TODO: Variable sized maps

class Map {
    public:
        Map();
        Tile tiles[16][16];
        Character characters[16][16];
        void place_character(int row, int col, Character &character);
        void move_character(Character &character, int key);
};

void load_map(Map &map, const char *name);

#endif
