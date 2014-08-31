#ifndef INVENTORY_H
#define INVENTORY_H

#include "items.hpp"

class Inventory {
	public:
		int totalweight;   /* Total weight of all items in the inventory */
		Item slots[256];   /* Array containing items */
		int quantity[256]; /* Array containing quantity of items */

		Inventory();
		int additem(Item item, int quantity);    /* Returns slot item was added to */
		int removeitem(Item item, int quantity); /* Returns slot item was removed from */
};

#endif
