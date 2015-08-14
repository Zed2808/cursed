#ifndef TILE_H
#define TILE_H

#include <string>

class Tile {
    public:
        Tile();
        unsigned char id;
        std::string name;
        char symbol;
        int color_pair;
        bool walkable;
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

Tile get_tile_from_id(unsigned char id);

#endif
