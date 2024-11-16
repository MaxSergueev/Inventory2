#pragma once
#include "IBakable.h"

class Mushroom : public IBakable {
public:
    std::string getName() const override { return "Mushroom"; }
};