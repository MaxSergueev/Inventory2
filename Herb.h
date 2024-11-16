#pragma once
#include "IBakable.h"

class Herb : public IBakable {
public:
    std::string getName() const override { return "Herb"; }
};