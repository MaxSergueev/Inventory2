#pragma once
#include "IBakable.h"
#include <string>
#include <iostream>
#include <typeinfo>
#include <memory>
#include "Vegetable.h"
#include "Herb.h"
#include "Mushroom.h"
#include "Meat.h"

class FoodProcessor {
public:
    void process(const IBakable& item1, const IBakable& item2) {
        std::string result;

        if (isVegetable(item1) && isHerb(item2) || isHerb(item1) && isVegetable(item2)) {
            result = "Vegetable Stew";
        }
        else if (isMushroom(item1) && isMeat(item2) || isMeat(item1) && isMushroom(item2)) {
            result = "Mushroom Premium Steak";
        }
        else {
            result = "Unknown Recipe";
        }

        std::cout << "Result: " << result << std::endl;
    }

private:
    bool isVegetable(const IBakable& item) const { return dynamic_cast<const Vegetable*>(&item) != nullptr; }
    bool isHerb(const IBakable& item) const { return dynamic_cast<const Herb*>(&item) != nullptr; }
    bool isMushroom(const IBakable& item) const { return dynamic_cast<const Mushroom*>(&item) != nullptr; }
    bool isMeat(const IBakable& item) const { return dynamic_cast<const Meat*>(&item) != nullptr; }
};