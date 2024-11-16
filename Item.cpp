#include "Item.h"

	Item::Item(std::string name, std::uint8_t itemType)
		:name(name), itemType(itemType) {}

    std::string Item::printItemType() const {
        std::ostringstream oss;

        if (itemType & ItemType::Type::Weapon) {
            oss << "Weapon ";
        }
        if (itemType & ItemType::Type::Armor) {
            oss << "Armor ";
        }
        if (itemType & ItemType::Type::Accessory) {
            oss << "Accessory ";
        }
        if (itemType & ItemType::Type::Potion) {
            oss << "Potion ";
        }
        if (itemType & ItemType::Type::Junk) {
            oss << "Junk ";
        }

        std::string typeStr = oss.str();
        return typeStr.empty() ? "Unknown" : typeStr;
    }

	std::string Item::getName() const {
		return name;
	}

    bool Item::hasTag(ItemType::Type tag) const {
        bool b = itemType & tag;
        std::cout << b << std::endl;
        return (b);
    }

    void Item::spreadFire() {
        if (itemType & ItemType::Type::Flammable) {
            if (!onFire) {
                std::cout << "- " << name << " caught fire and was destroyed" << std::endl;
            }
        }
        else {
            std::cout << "- " << name << " is not flammable." << std::endl;
        }
    }