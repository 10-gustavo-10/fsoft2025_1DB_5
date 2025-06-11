#include <utility>

#include "../../headers/model/Stadium.h"

Stadium::Stadium(std::string  name, int capacity, std::string  location)
    : name(std::move(name)), capacity(capacity), location(std::move(location)) {}

const std::string& Stadium::getName() const {
    return name;
}

int Stadium::getCapacity() const {
    return capacity;
}

const std::string& Stadium::getLocation() const {
    return location;
}
