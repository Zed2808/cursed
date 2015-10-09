#include "attacks.hpp"

Attack::Attack() {
    damage = 0;
    penetration = 0;
    range = 0;
}

Slash::Slash() {
    damage = 10;
    penetration = 0.5;
    range = 1;
}

Stab::Stab() {
    damage = 5;
    penetration = 0.95;
    range = 1;
}
