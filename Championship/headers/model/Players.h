#ifndef PLAYERS_H
#define PLAYERS_H

#include <string>

class Player {
private:
    std::string name;
    std::string position;
    int number;
    int goals;

public:
    Player(std::string  name, std::string  position, int number);

    const std::string& getName() const;
    const std::string& getPosition() const;
    int getNumber() const;
    int getGoals() const;

    void scoreGoal();
};

#endif

