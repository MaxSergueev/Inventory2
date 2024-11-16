#include "inventory.h"
#include "Item.h"

#include "FoodProcessor.h"
#include "Vegetable.h"
#include "Herb.h"
#include "Mushroom.h"
#include "Meat.h"

int main()
{
    Inventory inventory;

    auto healthPotion = std::make_unique<Item>("Health Potion", ItemType::Potion);
    auto potionPotion = std::make_unique<Item>("Potion Potion", ItemType::Potion);
    auto sword = std::make_unique<Item>("Iron Sword", ItemType::Weapon);
    auto mixedItem = std::make_unique<Item>("Rusty Wooden?? Sword", ItemType::Weapon | ItemType::Junk | ItemType::Flammable);
    auto garbage = std::make_unique<Item>("garbage", ItemType::Junk);


    sword->hasTag(ItemType::Accessory); //prints 0 as sword does not have tag 0.
    *sword += ItemType::Accessory;
    sword->hasTag(ItemType::Accessory);

    inventory.addItemSorted(std::move(healthPotion));
    inventory.addItemSorted(std::move(potionPotion));
    inventory.addItemSorted(std::move(sword));
    inventory.addItemSorted(std::move(mixedItem));
    inventory.addItemSorted(std::move(garbage));

    *inventory.items[0] += ItemType::Accessory;

    inventory.listItems();

    inventory - "garbage";

    inventory.listItems();

    inventory.setFire();
    inventory.listItems();


    /// Food Processor ///
    Vegetable veg;
    Herb herb;
    Mushroom mushroom;
    Meat meat;

    FoodProcessor processor;
    std::cout << "Time to Cook!" << std::endl;
    processor.process(veg, herb);
    processor.process(mushroom, meat);
    processor.process(veg, meat);

}
