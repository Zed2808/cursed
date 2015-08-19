#ifndef WEAPONS_H
#define WEAPONS_H

#include "items.hpp"
#include "character.hpp"

class Weapon : public Item {
    public:
        Weapon();
};

class Shortsword : public Weapon {
    public:
        Shortsword();
};

class BattleAxe : public Weapon {
    public:
        BattleAxe();
};

#endif
