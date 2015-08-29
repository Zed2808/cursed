#ifndef ITEMS_H
#define ITEMS_H

#include <string>

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

#endif
