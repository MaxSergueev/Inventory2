#pragma once
#include "IBakable.h"

class Vegetable : public IBakable {
public:
    std::string getName() const override { return "Vegetable"; }
};