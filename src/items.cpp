#include <string>
#include "items.hpp"
#include "attacks.hpp"

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
    primary = Attack();
    secondary = Attack();
}

/* 2 - Shortsword */
Shortsword::Shortsword() {
    name = "Shortsword";
    id = 0x02;
    weight = 5;
    primary = Slash();
    secondary = Stab();
}

/* 3 - Battle Axe */
BattleAxe::BattleAxe() {
    name = "Battle Axe";
    id = 0x03;
    weight = 8;
    primary = Slash();  // TODO: Replace these with battle axe specific attacks
    secondary = Stab();
}
