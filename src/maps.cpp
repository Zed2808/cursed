#ifdef __MINGW32__
#include <curses.h>
#endif

#ifdef __linux__
#include <ncurses.h>
#endif

#include <stdio.h>
#include <string.h>
#include "maps.hpp"
#include "npcs.hpp"
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
    int buffersize = 1024;            // Size of buffer
    unsigned char buffer[buffersize]; // Buffer to read map file into
    FILE *file = NULL;                // Pointer to actual map file

    /* Section buffers */
    unsigned char tilebuffer[1024];
    unsigned char charbuffer[1024];

    /* Store path to map file in dir */
    char dir[32];

    strcpy(dir, "data/maps/");
    strcat(dir, name);

    /* Open map file */
    file = fopen(dir, "rb");

    /* Read map file into buffer */
    fread(buffer, buffersize, 1, file);

    /* Read name */
    strncpy(map.name, reinterpret_cast<const char*>(buffer), 32);

    /* Read map dimensions */
    map.height = buffer[32];
    map.width = buffer[33];

    /* Prepare to read sections */
    bool reading = false;
    int index = 34; /* Start at first byte after name and dimensions */
    int start;      /* First byte of section */
    int end;        /* Last byte of section */

    /* Read entire tile section */
    if(buffer[index] == 0xff) { /* Byte at index matches section start byte */
        index++;
        start = index;
        reading = true;

        while(reading) {
            if(buffer[index] == 0xfd) { /* Byte at index matches section end byte */
                end = index;            /* Set end point of section read to the section end byte*/
                index++;                /* Increment index to prepare to read next section */
                reading = false;
            } else {
                index++;
            }
        }

        memcpy(tilebuffer, buffer + start, end - start);
    }

    /* Load individual tiles */
    int tileindex = 0; /* Start reading from first byte of tilebuffer */

    for(int row = 0; row < map.height; row++) {
        for(int col = 0; col < map.width; col++) {
            if(tilebuffer[tileindex] == 0xfe) { /* Byte at tileindex matches tile start byte */
                tileindex++;
                map.tiles[row][col] = get_tile_from_id(tilebuffer[tileindex]);
                tileindex++;
            }
        }
    }

    /* Read entire character section */
    if(buffer[index] == 0xff) { /* Byte at index where we left off matches section start byte */
        index++;
        start = index;
        reading = true;

        while(reading) {
            if(buffer[index] == 0xfd) { /* Byte at index matches section end byte */
                end = index;            /* Set end point of section read to the section end byte */
                reading = false;
            } else {
                index++;
            }
        }

        memcpy(charbuffer, buffer + start, end - start);
    }

    /* Load individual characters */
    reading = true;
    int charindex = 0; /* Start reading from the first byte of charbuffer */
    unsigned char charid;
    unsigned char charlevel;
    unsigned char charrow;
    unsigned char charcol;

    while(reading) {
        if(charbuffer[charindex] == 0xfe) { /* Byte at charindex matches character start byte */
            charindex++;
            charid = charbuffer[charindex];
            charindex++;
            charlevel = charbuffer[charindex];
            charindex++;
            charrow = charbuffer[charindex];
            charindex++;
            charcol = charbuffer[charindex];
            charindex++;

            Character newchar = get_npc_from_id(charid, charlevel);
            map.place_character(charrow, charcol, newchar);
        } else {
            reading = false;
        }
    }

    fclose(file);
}
