#ifndef TEAM_H
#define TEAM_H

#include <string>

class Team {
private:
    std::string name;
    int points;
    int goalsScored;
    int goalsConceded;
    int matchesPlayed;

public:
    Team(const std::string &name);

    const std::string &getName() const;
    int getPoints() const;
    int getGoalsScored() const;
    int getGoalsConceded() const;
    int getMatchesPlayed() const;
    int getGoalDifference() const;

    void updateStats(int goalsFor, int goalsAgainst);
};

#endif
