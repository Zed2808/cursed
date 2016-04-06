#ifndef ITEMS_H
#define ITEMS_H

#include <string>
#include "attacks.hpp"

/* Item */
class Item {
    public:
        std::string name;
        unsigned char id;
        unsigned char item_type;
        int weight;

        Item();
        virtual ~Item() {};
};

/* Weapons */
class Weapon : public Item {
    public:
        Attack primary;
        Attack secondary;

        Weapon();
};

/* Armor */
class Armor : public Item {
    public:
        Armor();
        unsigned char armor_piece;
        int armor;
};

/* Weapon - Shortsword */
class Shortsword : public Weapon {
    public:
        Shortsword();
};

/* Weapon - Battle Axe */
class BattleAxe : public Weapon {
    public:
        BattleAxe();
};

/* Weapon - Mace */
class Mace : public Weapon {
    public:
        Mace();
};

/* Weapon - Fork */
class Fork : public Weapon {
    public:
        Fork();
};

/* Armor - Iron Helmet */
class IronHelmet : public Armor {
    public:
        IronHelmet();
};

#endif
