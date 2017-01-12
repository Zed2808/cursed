#ifdef __MINGW32__
#include <curses.h>
#endif

#ifdef __linux__
#include <ncurses.h>
#endif

#include <math.h>
#include "attacks.hpp"
#include "character.hpp"
#include "gui.hpp"
#include "interaction.hpp"

void interact(Character &character, Character &target) {
    if(character.id == 0x00) {
        if(target.hostile) {
            draw_character_stats(target);
            attack(character, target);
        }
    }
}

void attack(Character &attacker, Character &defender) {
    // TODO: Check for range first
    Attack attack = attacker.weaponslot.attack1;
    int damage = ceil(attack.damage - (attack.penetration * defender.get_armor()));
    defender.health -= damage;
}
