#ifndef MAPS_H
#define MAPS_H

#include "tile.hpp"

class Map {
    public:
        Map();
        Tile tiles[16][16]; // TODO: Variable sized maps
};

#endif
