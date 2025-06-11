#include <utility>

#include "../../headers/model/Referee.h"

Referee::Referee(std::string  name, std::string  nationality)
    : name(std::move(name)), nationality(std::move(nationality)) {}

const std::string& Referee::getName() const {
    return name;
}

const std::string& Referee::getNationality() const {
    return nationality;
}
