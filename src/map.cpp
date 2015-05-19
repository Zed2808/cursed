#ifdef __MINGW32__
#include <curses.h>
#endif

#ifdef __linux__
#include <ncurses.h>
#endif

#include <iostream>
#include "map.hpp"

Map::Map() {
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			tiles[row][col] = NULL;
		}
	}
}

/*
 * Function: load_map
 *
 *   Loads specified map binary into map buffer
 */
void load_map(const char *mapname, Map &map) {
	unsigned char *buffer; // Pointer to buffered data
	FILE *file = NULL;     // File pointer

	file = fopen(mapname, "rb");

	buffer = new unsigned char[64];

	fread(buffer, 64, 1, file);

	delete[]buffer;
	fclose(file);
}

/*
 * Function: draw_map
 *
 *   Draws the specified map to the screen
 */
void draw_map(Map map) {
}
