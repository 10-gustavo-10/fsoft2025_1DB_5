#include "../../headers/model/Stadium.h"

Stadium::Stadium(const std::string& name, int capacity, const std::string& location)
    : name(name), capacity(capacity), location(location) {}

const std::string& Stadium::getName() const {
    return name;
}

int Stadium::getCapacity() const {
    return capacity;
}

const std::string& Stadium::getLocation() const {
    return location;
}
