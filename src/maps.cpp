#ifdef __MINGW32__
#include <curses.h>
#endif

#ifdef __linux__
#include <ncurses.h>
#endif

#include <stdio.h>
#include <string.h>
#include "maps.hpp"
#include "tile.hpp"

#define TEMPMAPHEIGHT 16
#define TEMPMAPWIDTH 16

// TODO: Variable sized maps

Map::Map() {
    for(int row = 0; row < TEMPMAPHEIGHT; row++) {
        for(int col = 0; col < TEMPMAPWIDTH; col++) {
            tiles[row][col] = Tile();
        }
    }

    for(int row = 0; row < TEMPMAPHEIGHT; row++) {
        for(int col = 0; col < TEMPMAPWIDTH; col++) {
            characters[row][col] = Character();
        }
    }
}

void Map::place_character(int row, int col, Character &character) {
    characters[row][col] = character;
    character.row = row;
    character.col = col;
}

void Map::move_character(Character &character, int key) {
    switch(key) {
        case KEY_UP:
            if(characters[character.row - 1][character.col].name != "") {
                // Interact
            } else if(character.row > 0 && tiles[character.row - 1][character.col].walkable) {
                characters[character.row][character.col] = Character();
                place_character(character.row - 1, character.col, character);
            }
            break;
        case KEY_DOWN:
            if(characters[character.row + 1][character.col].name != "") {
                // Interact
            } else if(character.row < TEMPMAPHEIGHT - 1 && tiles[character.row + 1][character.col].walkable) {
                characters[character.row][character.col] = Character();
                place_character(character.row + 1, character.col, character);
            }
            break;
        case KEY_LEFT:
            if(characters[character.row][character.col - 1].name != "") {
                // Interact
            } else if(character.col > 0 && tiles[character.row][character.col - 1].walkable) {
                characters[character.row][character.col] = Character();
                place_character(character.row, character.col - 1, character);
            }
            break;
        case KEY_RIGHT:
            if(characters[character.row][character.col + 1].name != "") {
                // Interact
            } else if(character.col < TEMPMAPWIDTH - 1 && tiles[character.row][character.col + 1].walkable) {
                characters[character.row][character.col] = Character();
                place_character(character.row, character.col + 1, character);
            }
            break;
    }
}

void load_map(Map &map, const char *name) {
    unsigned char *buffer; // Pointer to buffered data
    FILE *file = NULL;      // File pointer

    char mapname[32];
    char mapheight[1];
    char mapwidth[1];

    char dir[32];
    strcpy(dir, "data/maps/");
    strcat(dir, name);

    file = fopen(dir, "rb");

    buffer = new unsigned char[1024];

    fread(buffer, TEMPMAPHEIGHT * TEMPMAPWIDTH, 1, file);

    int index = 0;
    for(int row = 0; row < TEMPMAPHEIGHT; row++) {
        for(int col = 0; col < TEMPMAPWIDTH; col++) {
            map.tiles[row][col] = get_tile_from_id(buffer[index]);
            index++;
        }
    }

    delete[]buffer;
    fclose(file);
}
