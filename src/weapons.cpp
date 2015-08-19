#include <string>
#include "weapons.hpp"
#include "character.hpp"

/* Weapon */
Weapon::Weapon() {
    name = "";
    id = 0;
    weight = 0;
}

/* 1 - Shortsword */
Shortsword::Shortsword() {
    name = "Shortsword";
    id = 1;
    weight = 5;
}

/* 2 - Battle Axe */
BattleAxe::BattleAxe() {
    name = "Battle Axe";
    id = 2;
    weight = 8;
}
