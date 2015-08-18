#ifndef MAPS_H
#define MAPS_H

#include "tile.hpp"
#include "character.hpp"

// TODO: Variable sized maps

class Map {
    public:
        Map();
        char name[32];
        unsigned char height;
        unsigned char width;
        Tile tiles[16][16];
        Character **characters;
        void place_character(int row, int col, Character &character);
        void move_character(Character &character, int key);
};

void load_map(Map &map, const char *name);

#endif
