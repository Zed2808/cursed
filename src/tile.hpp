#ifndef TILE_H
#define TILE_H

#include <string>

class Tile {
    public:
        Tile();
        std::string name;
        char symbol;
        int fgcolor;
        int bgcolor;
};

class Grass : public Tile {
    public:
        Grass();
};

class Stone : public Tile {
    public:
        Stone();
};

#endif
