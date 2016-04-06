#include <algorithm>
#include "inventory.hpp"
#include "items.hpp"

/*
 * Entry
 */
Entry::Entry() {
    item = new Item();
    quantity = 0;
}

Entry::Entry(Item * new_item, int n) {
    item = new_item;
    quantity = n;
}

/*
 * Inventory
 */
Inventory::Inventory() {
    totalweight = 0;
}

/* Function: additem
 *   Adds item to first available slot in inventory
 *
 *   item: item to add
 *   n: number of item to add
 */
void Inventory::additem(Item * item, int n) {
    /* If no entries exist, simply push new entry */
    if(slots.size() == 0) {
        slots.push_back(Entry(item, n));
        totalweight += item->weight * n;
        return;
    }

    /* Iterate through entries searching for existing entry for item */
    for(unsigned int i = 0; i < slots.size(); i++) {
        /* Existing entry found for item at slots[i] */
        if(slots[i].item->id == item->id) {
            slots[i].quantity += n;
            totalweight += item->weight * n;
            return;
        }
    }

    /* Iterate through existing entries to place new entry alphabetically */
    std::vector<Entry>::iterator it = slots.begin();

    /* Convert item name to lowercase */
    std::string lowercase_item = item->name;
    std::transform(lowercase_item.begin(), lowercase_item.end(), lowercase_item.begin(), ::tolower);

    /* Create string to store lower case entry name */
    std::string lowercase_entry;

    /* Must run at least once in case there's only one entry (slots.begin() == slots.end()) */
    do {
        Entry entry = *it;
        /* Convert entry name to lowercase (in ASCII A != a) */
        lowercase_entry = entry.item->name;
        std::transform(lowercase_entry.begin(), lowercase_entry.end(), lowercase_entry.begin(), ::tolower);
        /* If new item should come before entry at it */
        if(lowercase_item < lowercase_entry) {
            slots.insert(it, Entry(item, n));
            totalweight += item->weight * n;
            return;
        }
        it++;
    } while(it != slots.end());

    /* Item to add comes last alphabetically */
    slots.push_back(Entry(item, n));
    totalweight += item->weight * n;
}

/* Function: removeitem
 *   Searches inventory for item and removes it
 *
 *   item: item to search for for removal
 *   quantity: number of item to remove
 *
 *   Returns slot in inventory item was removed from
 */
void Inventory::removeitem(Item * item, int n) {
    /* Iterate through entries searching for existing entry for item */
    for(unsigned int i = 0; i < slots.size(); i++) {
        /* Existing entry found for item */
        if(slots[i].item->id == item->id) {
            /* Removing more or the same amount of an item than is listed in entry */
            if(n >= slots[i].quantity) {
                totalweight -= item->weight * slots[i].quantity; /* Only decrement totalweight by weight of items being removed */
                slots.erase(slots.begin() + i);                  /* Remove entire entry at i */
            } else {
                totalweight -= item->weight * n;
                slots[i].quantity -= n;
            }
        }
    }
}

/*
 * EquipSlot
 */
EquipSlot::EquipSlot() {
    equipped = new Weapon();
    attack1 = Attack();
    attack2 = Attack();
}

/* Function: equip
 *   Moves 1 of specified item from inventory to equip slot
 *
 *   inventory: inventory to remove item from
 *   item: item to equip from inventory
 */
void EquipSlot::equip(Inventory &inventory, Weapon * weapon) {
    /* Only move item back to inventory if it isn't default weapon */
    if(equipped->id != 0x01) {
        inventory.additem(equipped, 1);
    }
    inventory.removeitem(weapon, 1);
    equipped = weapon;
    attack1 = weapon->primary;
    attack2 = weapon->secondary;
}

/* Function: unequip
 *   Moves item from equip slot back into inventory
 *
 *   inventory: inventory to move item back into
 */
void EquipSlot::unequip(Inventory &inventory) {
    inventory.additem(equipped, 1);
    equipped = new Weapon();
    attack1 = Attack();
    attack2 = Attack();
}
