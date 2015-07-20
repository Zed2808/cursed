#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "inventory.hpp"

class Character {
    public:
        /* Inventory Stuff */
        Inventory inventory;
        EquipSlot equipslot;

        /* Current Stats */
        std::string name;
        int level;

        int health;
        int mana;
        int stamina;

        /* Main Attributes */
        int endurance;		/* Affects health */
        int intelligence;	/* Affects mana */
        int agility;		/* Affects stamina */
        int strength;		/* Affects carry weight */
        int personality;
        int perception;
        int luck;

        /* Derived Attributes */
        int maxhealth;
        int maxmana;
        int maxstamina;
        int carryweight;
};

#endif
