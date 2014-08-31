#include <algorithm>
#include "inventory.hpp"
#include "items.hpp"

Inventory::Inventory() {
	totalweight = 0;
	std::fill_n(slots, 256, Item());
	std::fill_n(quantity, 256, 0);
}

/* Function: additem
 *   Adds item to first available slot in inventory
 *
 *   item: item to add
 *   n: number of item to add
 *
 *   Returns slot in inventory item was added to
 */
int Inventory::additem(Item item, int n) {
	for(int i = 0; i <= 255; i++) { /* Loop to search for matching itemid */
		if(slots[i].get_itemid() == item.get_itemid()) { /* If itemid in slot matches that of the item we're trying to add */
			quantity[i] += n; /* Don't change item in slot, just add n to quantity of that slot */
			return i; /* Return index of slot of which the quantity was increased */
		}
	}

	for(int i = 0; i <= 255; i++) { /* Loop to search for empty slot */
		if(quantity[i] == 0) { /* Slot is empty */
			slots[i] = item;
			quantity[i] = n;
			return i;
		}
	}

	return -1; /* Return -1 if item could not be added to a slot */
}

/* Function: removeitem
 *   Searches inventory for item and removes it
 *
 *   item: item to search for for removal
 *   quantity: number of item to remove
 *
 *   Returns slot in inventory item was removed from
 */
int Inventory::removeitem(Item item, int n) {
	for(int i = 0; i <= 255; i++) { /* Loop to search for matching itemid */
		if(slots[i].get_itemid() == item.get_itemid()) { /* If itemid in slot matches that of the item we're trying to remove */
			quantity[i] -= n;
			if(quantity[i] <= 0) { /* If removing items emptied that slot */
				quantity[i] = 0; /* Set quantity to 0 to avoid negative quantities */
				slots[i] = Item(); /* Set item in slot to "empty" */
				return i; /* Return slot item was removed from */
			}
		}
	}
	return -1; /* Return -1 if item could not be removed */
}
