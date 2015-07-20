#ifndef TILE_H
#define TILE_H

#include <string>

class Tile {
    public:
        Tile();
        int id;
        std::string name;
        char symbol;
        int color_pair;
};

class Grass : public Tile {
    public:
        Grass();
};

class Stone : public Tile {
    public:
        Stone();
};

class Wall : public Tile {
    public:
        Wall();
};

Tile get_tile_from_id(int id);

#endif
