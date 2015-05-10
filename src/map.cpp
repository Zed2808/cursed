#ifdef __MINGW32__
#include <curses.h>
#endif

#ifdef __linux__
#include <ncurses.h>
#endif

#include <iostream>
#include "map.hpp"

typedef unsigned char BYTE;

/*
 * Function: load_map
 *
 *   Loads specified map binary into map buffer
 */
void load_map(const char *mapname, Map &map) {
	BYTE *buffer[64];  // Pointer to buffered data
	FILE *file = NULL; // File pointer

	file = fopen(mapname, "rb");
	fread(buffer, 64, 1, file);
	fclose(file);

	// Test map reading
	for (int i = 0; i < 64; i++) {
		printf("%X", buffer[i]);
	}
}

/*
 * Function: draw_map
 *
 *   Draws the specified map to the screen
 */
void draw_map(Map map) {
}
