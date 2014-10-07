#ifndef ITEMS_H
#define ITEMS_H

#include <string>

class Item {
	protected:
		std::string name;
		int itemid;
		int weight;
	public:
		Item();
		std::string get_name();
		int get_itemid();
		int get_weight();
};

#endif
