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
	bool exit = false;
	int i = 0;
	while(!exit && i <= 255) { /* Loop to search for first open slot */
		if(slots[i].get_name() == "") { /* If item name in slot is "" (slot is not occupied) */
			slots[i] = item;
			quantity[i] = n;
			exit = true;
		} else { /* Slot is occupied */
			i++; /* Move on to the next slot */
		}
	}

	if(i > 255) { /* Open slot could not be found */
		return -1;
	} else {
		return i; /* Return slot item was added to */
	}
}

/* Function: removeitem
 *   Searches inventory for item and removes it
 *
 *   item: item to search for for removal
 *   quantity: number of item to remove
 *
 *   Returns slot in inventory item was removed from
 */
int Inventory::removeitem(Item item, int quantity) {
	return 0;
}
