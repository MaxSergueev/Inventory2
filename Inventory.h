#pragma once
#include <vector>
#include <memory>
#include "item.h"

class Inventory {
private:
    //std::vector<std::unique_ptr<Item>> items;

public:

    std::vector<std::unique_ptr<Item>> items;

    // Function to add an item to the inventory
    //void addItem(std::unique_ptr<Item> item);

    // Function to list all items in the inventory
    void listItems() const;

    void setFire();

    // Overloaded operators
    //Add an item
    Inventory& operator+(std::unique_ptr<Item> item) {
        items.push_back(std::move(item));
        return *this;
    }

    //remove an item
    Inventory& operator-(const std::string& itemName) {
        auto it = std::remove_if(items.begin(), items.end(),
            [&itemName](const std::unique_ptr<Item>& item) {
                return item->getName() == itemName; 
            });

        if (it != items.end()) {
            items.erase(it, items.end());
        }
        return *this;
    }

};
