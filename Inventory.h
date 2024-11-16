#pragma once
#include <vector>
#include <memory>
#include "item.h"

class Inventory {
private:

public:

    std::vector<std::unique_ptr<Item>> items;

    void listItems() const;

    void setFire();

    void addItemSorted(std::unique_ptr<Item> item);

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
