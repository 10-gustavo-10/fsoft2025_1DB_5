#include "../../headers/model/Players.h"

Player::Player(const std::string& name, const std::string& position, int number)
    : name(name), position(position), number(number), goals(0) {}

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
