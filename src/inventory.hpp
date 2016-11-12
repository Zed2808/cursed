#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "attacks.hpp"
#include "items.hpp"

class Entry {
    public:
        Item * item;
        int quantity;

        Entry();
        Entry(Item * new_item, int n);
};

class Inventory {
    public:
        std::vector<Entry> slots;
        int totalweight;

        Inventory();
        void additem(Item * item, int n);
        void removeitem(Item * item, int n);
};

class WeaponSlot {
    public:
        Weapon * equipped;
        Attack attack1;
        Attack attack2;

        WeaponSlot();
        void equip(Inventory &inventory, Weapon * Weapon); /* Moves 1 of item from inventory to WeaponSlot */
        void unequip(Inventory &inventory);                /* Moves item in weapon slot back to inventory */
};

#endif
