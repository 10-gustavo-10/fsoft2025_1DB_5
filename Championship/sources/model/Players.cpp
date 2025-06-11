#include <utility>

#include "../../headers/model/Players.h"

Player::Player(std::string  name, std::string  position, const int number)
    : name(std::move(name)), position(std::move(position)), number(number), goals(0) {}

const std::string& Player::getName() const {
    return name;
}

const std::string& Player::getPosition() const {
    return position;
}

int Player::getNumber() const {
    return number;
}

int Player::getGoals() const {
    return goals;
}

void Player::scoreGoal() {
    goals++;
}
