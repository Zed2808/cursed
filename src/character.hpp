#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "inventory.hpp"

class Character {
    protected:
        /* Main Attributes */
        int endurance;		/* Affects health */
        int intelligence;	/* Affects mana */
        int agility;		/* Affects stamina */
        int strength;		/* Affects carry weight */
        int personality;
        int perception;
        int luck;

        /* Derived Attributes */
        int maxhealth;
        int maxmana;
        int maxstamina;
        int carryweight;
        int armor;

    public:
        Character();

        /* Basic Info */
        std::string name;
        unsigned char id;
        std::string str_id;
        int level;
        bool hostile;

        /* Current Stats */
        int health;
        int mana;
        int stamina;

        /* Map stuff */
        char symbol;
        int color_pair;
        int row;
        int col;

        /* Inventory stuff */
        Inventory inventory;
        EquipSlot equipslot;


        /* Sets & Gets for current stats */
        void set_name(std::string n);
        std::string get_name();
        void set_level(int l);
        int get_level();

        void set_health(int h);
        int get_health();
        void set_mana(int m);
        int get_mana();
        void set_stamina(int s);
        int get_stamina();

        /* Sets & Gets for main attributes */
        void set_endurance(int e);
        int get_endurance();
        void set_intelligence(int i);
        int get_intelligence();
        void set_agility(int a);
        int get_agility();
        void set_strength(int s);
        int get_strength();
        void set_personality(int p);
        int get_personality();
        void set_perception(int p);
        int get_perception();
        void set_luck(int l);
        int get_luck();

        /* Gets for derived attributes */
        int get_maxhealth();
        int get_maxmana();
        int get_maxstamina();
        int get_carryweight();
        int get_armor();
};

#endif
