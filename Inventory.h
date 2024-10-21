#pragma once
#include <vector>
#include <memory>
#include "item.h"

class Inventory {
private:
    //std::vector<std::unique_ptr<Item>> items; // Use smart pointers for automatic memory management

public:

    std::vector<std::unique_ptr<Item>> items; // Use smart pointers for automatic memory management

    // Function to add an item to the inventory
    //void addItem(std::unique_ptr<Item> item);

    // Function to list all items in the inventory
    void listItems() const;

    void setFire();

    // Overloaded operators
    Inventory& operator+(std::unique_ptr<Item> item) {
        items.push_back(std::move(item));
        return *this;
    }

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
