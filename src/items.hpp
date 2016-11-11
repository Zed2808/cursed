#ifndef ITEMS_H
#define ITEMS_H

#include <string>
#include "attacks.hpp"

enum class ItemType {
    UNDEFINED,
    WEAPON,
    ARMOR
};

enum class ArmorSlot {
    UNDEFINED,
    HELMET,
    CUIRASS,
    GREAVES,
    GLOVES,
    BOOTS,
    NECKLACE,
    RING
};

/* Item */
class Item {
    public:
        std::string name;
        unsigned char id;
        ItemType item_type;
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
        ArmorSlot armor_slot;
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
