#include "attacks.hpp"

Attack::Attack() {
    name = "";
    damage = 0;
    penetration = 0;
    range = 0;
}

Slash::Slash() {
    name = "Slash";
    damage = 5;
    penetration = 0.5;
    range = 1;
}

Stab::Stab() {
    name = "Stab";
    damage = 8;
    penetration = 0.95;
    range = 1;
}

Chop::Chop() {
    name = "Chop";
    damage = 9;
    penetration = 0.75;
    range = 1;
}

Smash::Smash() {
    name = "Smash";
    damage = 10;
    penetration = 0.2;
    range = 1;
}
