#include "../../headers/model/League.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

League::~League() {
    for (auto* match : matches) delete match;
    for (auto* team : teams) delete team;
}

void League::addTeam(Team* team) {
    teams.push_back(team);

    void League::addMatch(Match* match) {
        matches.push_back(match);
    }

    const std::vector<Team*>& League::getTeams() const {
        return teams;
    }

    void League::showStandings() const {
        std::vector<Team*> sortedTeams = teams;

        std::sort(sortedTeams.begin(), sortedTeams.end(), [](Team* a, Team* b) {
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
                  << std::setw(8) << "Pts"
                  << std::setw(8) << "GM"
                  << std::setw(8) << "GS"
                  << std::setw(8) << "Dif"
                  << std::setw(8) << "J\n";
        std::cout << "-------------------------------------------\n";

        for (const auto* team : sortedTeams) {
            std::cout << std::left << std::setw(18) << team->getName()
                      << std::setw(8) << team->getPoints()
                      << std::setw(8) << team->getGoalsScored()
                      << std::setw(8) << team->getGoalsConceded()
                      << std::setw(8) << team->getGoalDifference()
                      << std::setw(8) << team->getMatchesPlayed()
                      << "\n";
        }

        std::cout << "-------------------------------------------\n";
    }

