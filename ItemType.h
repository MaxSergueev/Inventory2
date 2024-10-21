#pragma once
namespace ItemType {
    enum Type {
        Weapon = 1 << 0, //1
        Armor = 1 << 1, //2
        Accessory = 1 << 2, //4
        Potion = 1 << 3, //8
        Junk = 1 << 4, //16
        Flammable = 1 << 5 //32
    };
}