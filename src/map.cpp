#include "map.hpp"
#include "tile.hpp"

// TODO: Variable sized maps

Map::Map() {
    for (int row = 0; row < 16; row++) {
        for (int col = 0; col < 16; col++) {
            tiles[row][col] = Tile();
        }
    }
}
