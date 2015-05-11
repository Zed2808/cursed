#ifndef MAP_H
#define MAP_H


class Map {
	protected:
		int ids [8][8];
    public:
        Map();
};

//void load_map(const char *mapname, Map map);
void load_map();
void draw_map(Map map);

#endif
