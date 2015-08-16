#include "player.hpp"
#include <string>

Player::Player() {
    name = "Default";
    id = 0x00;
    level = 1;
    symbol = '@';
    color_pair = 5;
    row = 0;
    col = 0;
    set_endurance(5);
    set_intelligence(5);
    set_agility(5);
    set_strength(5);
    set_personality(5);
    set_perception(5);
    set_luck(5);
}
