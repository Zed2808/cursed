#ifndef WEAPONS_H
#define WEAPONS_H

#include "items.hpp"
#include "character.hpp"

class Weapon : public Item {
    protected:
        int damage;
    public:
        Weapon();
        int get_damage();
        /* Get weapon's attacks */
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
