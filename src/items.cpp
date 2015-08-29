#include <string>
#include "items.hpp"

/* 0 - Base Item */
Item::Item() {
    name = "";
    id = 0x00;
    weight = 0;
}



/* 1 - Weapon */
Weapon::Weapon() {
    name = "";
    id = 0x01;
    weight = 0;
}

/* 2 - Shortsword */
Shortsword::Shortsword() {
    name = "Shortsword";
    id = 0x02;
    weight = 5;
}

/* 3 - Battle Axe */
BattleAxe::BattleAxe() {
    name = "Battle Axe";
    id = 0x03;
    weight = 8;
}
