#pragma once
#include "IBakable.h"

class Meat : public IBakable {
public:
    std::string getName() const override { return "Meat"; }
};