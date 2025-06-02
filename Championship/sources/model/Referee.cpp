#include "../../headers/model/Referee.h"

Referee::Referee(const std::string& name, const std::string& nationality)
    : name(name), nationality(nationality) {}

const std::string& Referee::getName() const {
    return name;
}

const std::string& Referee::getNationality() const {
    return nationality;
}
