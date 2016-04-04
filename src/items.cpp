#include <string>
#include "items.hpp"
#include "attacks.hpp"

/*
 * Item types:
 * 00 Test/other
 * 01 Weapon
 * 02 Armor
 */

/* 0 - Default Item */
Item::Item() {
    name = "";
    id = 0x00;
    item_type = 0x00;
    weight = 0;
}

/* 1 - Default Weapon */
Weapon::Weapon() {
    name = "";
    id = 0x01;
    item_type = 0x01;
    weight = 0;
    primary = Attack();
    secondary = Attack();
}

/* 2 - Shortsword */
Shortsword::Shortsword() {
    name = "Shortsword";
    id = 0x02;
    item_type = 0x01;
    weight = 5;
    primary = Slash();
    secondary = Stab();
}

/* 3 - Battle Axe */
BattleAxe::BattleAxe() {
    name = "Battle Axe";
    id = 0x03;
    item_type = 0x01;
    weight = 8;
    primary = Slash();
    secondary = Chop();
}

/* 4 - Mace */
Mace::Mace() {
    name = "Mace";
    id = 0x04;
    item_type = 0x01;
    weight = 6;
    primary = Slash();
    secondary = Smash();
}

/* 5 - Fork */
Fork::Fork() {
    name = "Fork";
    id = 0x05;
    item_type = 0x01;
    weight = 1;
    primary = Slash();
    secondary = Stab();
}

/* 6 - Iron Helmet */
IronHelmet::IronHelmet() {
    name = "Iron Helmet";
    id = 0x06;
    item_type = 0x02;
    weight 2;
    armor = 2;
}
