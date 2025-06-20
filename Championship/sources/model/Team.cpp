#include <utility>
#include "../../headers/model/Team.h"
#include "../../headers/model/Players.h"

Team::Team(std::string name)
    : name(std::move(name)), points(0), goalsScored(0), goalsConceded(0), matchesPlayed(0) {}

const std::string& Team::getName() const {
    return name;
}

int Team::getPoints() const {
    return points;
}

int Team::getGoalsScored() const {
    return goalsScored;
}

int Team::getGoalsConceded() const {
    return goalsConceded;
}

int Team::getMatchesPlayed() const {
    return matchesPlayed;
}

int Team::getGoalDifference() const {
    return goalsScored - goalsConceded;
}

void Team::updateStats(int goalsFor, int goalsAgainst) {
    goalsScored += goalsFor;
    goalsConceded += goalsAgainst;
    matchesPlayed++;

    if (goalsFor > goalsAgainst) {
        points += 3;
    } else if (goalsFor == goalsAgainst) {
        points += 1;
    }

}

void Team::addPlayer(Player* player) {
    players.push_back(player);
}

const std::vector<Player*>& Team::getPlayers() const {
    return players;
}
