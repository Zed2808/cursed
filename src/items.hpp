#ifndef ITEMS_H
#define ITEMS_H

#include <string>

class Item {
    public:
        Item();
        std::string name;
        unsigned char id;
        int weight;
};

#endif
