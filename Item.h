#pragma once
#include <iostream>
#include <sstream>
#include "ItemType.h"
#include "Flammable.h"

class Item : public Flammable {
	private:
		std::string name;
		std::uint8_t itemType;
		bool onFire = false;

	public: 
		Item(std::string name = "Junk", std::uint8_t itemType = ItemType::Junk);

		std::string getName() const;
		std::string printItemType() const;
		std::uint8_t getItemType() const { return itemType; }
        bool hasTag(ItemType::Type tag) const;
		void spreadFire() override;

		//Overridden Operators
        //Create new item with added tag
        Item operator+(ItemType::Type tag) const {
            return Item(name, itemType | static_cast<std::uint8_t>(tag));
        }
        //Add tag to selected item
        Item& operator+=(ItemType::Type tag) {
            itemType |= static_cast<std::uint8_t>(tag);
            return *this;
        }

        //Create new item with subtracted tag
        Item operator-(ItemType::Type tag) const {
            return Item(name, itemType & ~static_cast<std::uint8_t>(tag));
        }
        //Subtract tag from selected item
        Item& operator-=(ItemType::Type tag) {
            itemType &= ~static_cast<std::uint8_t>(tag);
            return *this;
        }

};

