#include <string>
#include "npcs.hpp"

/*
 * Wolf
 */
Wolf::Wolf(int l) {
    name = "Wolf";
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
