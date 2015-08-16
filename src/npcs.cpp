#include <string>
#include "npcs.hpp"

/*
 * Wolf
 */
Wolf::Wolf(int l) {
    name = "Wolf";
    id = 0x01;
    level = l;
    hostile = true;
    symbol = 'w';
    color_pair = 1;
    maxhealth = 10;
    health = maxhealth;
    maxmana = 0;
    mana = maxmana;
    maxstamina = 10;
    stamina = maxstamina;
}

Rat::Rat(int l) {
    name = "Rat";
    id = 0x02;
    level = l;
    hostile = true;
    symbol = 'r';
    color_pair = 1;
    maxhealth = 5;
    health = maxhealth;
    maxmana = 0;
    mana = maxmana;
    maxstamina = 5;
    stamina = maxstamina;
}

Character get_npc_from_id(unsigned char id, unsigned char level) {
    switch (id) {
        case 0x01:
            return Wolf(level);
            break;
        case 0x02:
            return Rat(level);
            break;
        default:
            return Character();
    }
}
