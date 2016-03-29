#ifndef ITEMS_H
#define ITEMS_H

#include <string>
#include "attacks.hpp"

/* Item */
class Item {
    public:
        Item();
        std::string name;
        unsigned char id;
        int weight;
};



/* Weapons */
class Weapon : public Item {
    public:
        Weapon();
        Attack primary;
        Attack secondary;
};

/* Shortsword */
class Shortsword : public Weapon {
    public:
        Shortsword();
};

/* Battle Axe */
class BattleAxe : public Weapon {
    public:
        BattleAxe();
};

/* Mace */
class Mace : public Weapon {
    public:
        Mace();
};

/* Fork */
class Fork : public Weapon {
    public:
        Fork();
};

#endif
