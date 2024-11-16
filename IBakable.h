#pragma once
#include <string>

class IBakable {
public:
    virtual std::string getName() const = 0;
    virtual ~IBakable() = default;
};