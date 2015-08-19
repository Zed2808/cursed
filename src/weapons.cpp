#include <string>
#include "weapons.hpp"
#include "character.hpp"

/* Weapon */
Weapon::Weapon() {
    name = "";
    id = 0x01;
    weight = 0;
}

/* 1 - Shortsword */
Shortsword::Shortsword() {
    name = "Shortsword";
    id = 0x02;
    weight = 5;
}

/* 2 - Battle Axe */
BattleAxe::BattleAxe() {
    name = "Battle Axe";
    id = 0x03;
    weight = 8;
}
