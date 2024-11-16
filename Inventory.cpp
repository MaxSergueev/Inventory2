#include "inventory.h"
#include <iostream>

void Inventory::listItems() const {
    if (items.empty()) {
        std::cout << "Inventory is empty." << std::endl;
        return;
    }

    std::cout << "Items in inventory:" << std::endl;
    for (const auto& item : items) {
        std::cout << "- " << item->getName() << ", its item type is: " << item->printItemType() << std::endl;
    }
    std::cout << " ------------------------------- " << std::endl;
}

void Inventory::setFire() {
    std::cout << "Oh no! A fire is spreading! " << std::endl;
    for (const auto& item : items) {
        item->spreadFire();
    }

    items.erase(std::remove_if(items.begin(), items.end(),
        [](const std::unique_ptr<Item>& item) {
            return item->getItemType() & ItemType::Flammable;
        }), items.end());

    std::cout << " ------------------------------- " << std::endl;
}

void Inventory::addItemSorted(std::unique_ptr<Item> item) {
    auto it = std::find_if(
        items.begin(),
        items.end(),
        [&item](const std::unique_ptr<Item>& existingItem) {
            return existingItem->getItemType() > item->getItemType();
        }
    );

    items.insert(it, std::move(item));
}