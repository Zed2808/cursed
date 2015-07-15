#ifndef MAP_H
#define MAP_H

#include "tile.hpp"

class Map {
    public:
        Map();
        Tile tiles[8][8]; // TODO: Variable sized maps
};

#endif
