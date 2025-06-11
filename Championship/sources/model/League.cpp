#include "../../headers/model/League.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

League::~League() {
    for (const auto* m : matches) delete m;
    for (const auto* t : teams) delete t;
}

void League::addTeam(Team* team) {
    teams.push_back(team);
}

void League::addMatch(Match* match) {
    matches.push_back(match);
}

const std::vector<Team*>& League::getTeams() const {
    return teams;
}

const std::vector<Match*>& League::getMatches() const {
    return matches;
}

void League::showStandings() const {

    std::vector<Team*> sortedTeams = teams;

    std::sort(sortedTeams.begin(), sortedTeams.end(), [](const Team* a, const Team* b) {
        if (a->getPoints() != b->getPoints())
            return a->getPoints() > b->getPoints();

        if (a->getGoalDifference() != b->getGoalDifference())
            return a->getGoalDifference() > b->getGoalDifference();

        if (a->getGoalsScored() != b->getGoalsScored())
            return a->getGoalsScored() > b->getGoalsScored();

        return a->getName() < b->getName();
    });

    std::cout << "\n----------- Classificação Atual -----------\n";
    std::cout << std::left << std::setw(18) << "Equipa"
              << std::setw(6) << "Pts"
              << std::setw(6) << "GM"
              << std::setw(6) << "GS"
              << std::setw(6) << "Dif"
              << std::setw(4) << "J" << "\n";
    std::cout << "-------------------------------------------\n";

    for (const auto* team : sortedTeams) {
        std::cout << std::left << std::setw(18) << team->getName()
                  << std::setw(6) << team->getPoints()
                  << std::setw(6) << team->getGoalsScored()
                  << std::setw(6) << team->getGoalsConceded()
                  << std::setw(6) << team->getGoalDifference()
                  << std::setw(4) << team->getMatchesPlayed()
                  << "\n";
    }

    std::cout << "-------------------------------------------\n";
}