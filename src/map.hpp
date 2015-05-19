#ifndef MAP_H
#define MAP_H


class Map {
	protected:
		unsigned char tiles[8][8];
	public:
		Map();
};

void load_map(const char *mapname, Map &map);
void draw_map(Map map);

#endif
