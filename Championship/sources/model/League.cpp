#include "../../headers/model/League.h"
#include <iostream>

League::~League() {
    for (auto m : matches) delete m;
    for (auto t : teams) delete t;
}

void League::addTeam(Team* team) {
    teams.push_back(*team);
}

void League::addMatch(Match* match) {
    matches.push_back(match);
}

void League::showStandings() const {

    std::vector<Team*> sortedTeams ;
    std::sort(sortedTeams.begin(), sortedTeams.end(), [](Team* a, Team* b) {
        if (a->getPoints() != b->getPoints())
            return a->getPoints() > b->getPoints();
        return a->getGoalDifference() > b->getGoalDifference();
    });

    std::cout << "\nClassificação Atual:\n";
    std::cout << "-------------------------------------------\n";
    std::cout << "Equipa         Pontos   GM  GS  DG\n";
    std::cout << "-------------------------------------------\n";
    for (auto team : sortedTeams) {
        std::cout << team->getName() << "\t"
                  << team->getPoints() << "\t"
                  << team->getGoalsScored() << "  "
                  << team->getGoalsConceded() << "  "
                  << team->getGoalDifference() << "\n";
    }
    std::cout << "-------------------------------------------\n";
}

const std::vector<Team> &League::getTeams() const {
    return teams;
}