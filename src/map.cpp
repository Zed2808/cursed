#ifdef __MINGW32__
#include <curses.h>
#endif

#ifdef __linux__
#include <ncurses.h>
#endif

#include <iostream>
#include "map.hpp"

typedef unsigned char BYTE;

Map::Map() {
}

/*
 * Function: load_map
 *
 *   Loads specified map binary into map buffer
 */
//void load_map(const char *mapname, Map map) {
void load_map() {
	BYTE *buffer[64];  // Pointer to buffered data
	FILE *file = NULL; // File pointer

	//file = fopen(mapname, "rb");
    file = fopen("data/maps/map001", "rb");
	fread(buffer, 64, 1, file);

	// Test map reading
	for (int i = 0; i < 64; i++) {
		printf("%X", buffer[i]);
	}

    fclose(file);
}

/*
 * Function: draw_map
 *
 *   Draws the specified map to the screen
 */
void draw_map(Map map) {
}
