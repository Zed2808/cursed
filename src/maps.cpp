#include <stdio.h>
#include <string.h>
#include "maps.hpp"
#include "tile.hpp"

// TODO: Variable sized maps

Map::Map() {
    for(int row = 0; row < 16; row++) {
        for(int col = 0; col < 16; col++) {
            tiles[row][col] = Tile();
        }
    }
}

void load_map(Map &map, const char *name) {
    unsigned char *buffer; // Pointer to buffered data
    FILE *file = NULL;      // File pointer

    char dir[32];
    strcpy(dir, "data/maps/");
    strcat(dir, name);

    file = fopen(dir, "rb");

    buffer = new unsigned char[256];

    fread(buffer, 256, 1, file);

    int index = 0;
    for(int row = 0; row < 16; row++) {
        for(int col = 0; col < 16; col++) {
            map.tiles[row][col] = get_tile_from_id(buffer[index]);
            index++;
        }
    }

    delete[]buffer;
    fclose(file);
}
