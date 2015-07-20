#ifndef MAPS_H
#define MAPS_H

#include "tile.hpp"

// TODO: Variable sized maps

class Map {
    public:
        Map();
        Tile tiles[16][16];
};

void load_map(Map &map, const char *name);

#endif
