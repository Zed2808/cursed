#include <string>
#include "npcs.hpp"

/*
 * Wolf
 */
Wolf::Wolf(int l) {
    name = "Wolf";
    level = l;
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
    maxhealth = 5;
    health = maxhealth;
    maxmana = 0;
    mana = maxmana;
    maxstamina = 5;
    stamina = maxstamina;
}
