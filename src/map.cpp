#include "map.hpp"
#include "tile.hpp"

// TODO: Variable sized maps

Map::Map() {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            tiles[row][col] = Tile();
        }
    }
}
