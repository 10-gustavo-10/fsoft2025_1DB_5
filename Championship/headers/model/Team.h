#pragma once

#include <string>
#include <vector>


class Player;

class Team {
private:
    std::string name;
    int points;
    int goalsScored;
    int goalsConceded;
    int matchesPlayed;
    std::vector<Player*> players;

public:
    explicit Team(std::string name);

    const std::string &getName() const;
    int getPoints() const;
    int getGoalsScored() const;
    int getGoalsConceded() const;
    int getMatchesPlayed() const;
    int getGoalDifference() const;

    void updateStats(int goalsFor, int goalsAgainst);


    void addPlayer(Player* player);
    const std::vector<Player*>& getPlayers() const;
};

