#include "inventory.h"
#include "Item.h"

int main()
{
    Inventory inventory;

    auto healthPotion = std::make_unique<Item>("Health Potion", ItemType::Potion);
    auto sword = std::make_unique<Item>("Iron Sword", ItemType::Weapon);
    auto mixedItem = std::make_unique<Item>("Rusty Sword", ItemType::Weapon | ItemType::Junk | ItemType::Flammable);
    auto garbage = std::make_unique<Item>("garbage", ItemType::Junk);

    *sword += ItemType::Accessory;
    sword->hasTag(ItemType::Potion);

    inventory + std::move(healthPotion);
    inventory + std::move(sword);
    inventory + std::move(mixedItem);
    inventory + std::move(garbage);

    *inventory.items[0] += ItemType::Accessory;

    inventory.listItems();

    inventory - "garbage";

    inventory.listItems();

    inventory.setFire();
    inventory.listItems();

}
