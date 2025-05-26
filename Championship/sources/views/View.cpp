#include "../../headers/views/View.h"
#include "../../headers/controllers/ChampionshipController.h"
#include "../../headers/model/League.h"
#include <iostream>

void View::menu(ChampionshipController& controller) {
    int option;
    League league;
    std::vector<Team> teams = league.getTeams();
    do {
        std::cout << "\n1. Register match result\n";
        std::cout << "2. Show standings\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> option;
        if (option == 1) {
            int id1, id2, g1, g2;

            for (size_t i = 0; i < teams.size(); i++)
                std::cout << i << " - " << teams[i].getName()<< '\n';

            std::cout << "Home team ID: "; std::cin >> id1;
            std::cout << "Away team ID: "; std::cin >> id2;
            std::cout << "Goals home team: "; std::cin >> g1;
            std::cout << "Goals away team: "; std::cin >> g2;


            league.addMatch(id1, id2, g1, g2);
        }
        else if (option == 2) {
            showStandings(teams);
        }

    } while (option != 0);
}

void View::showStandings(const std::vector<Team>& teams) {
    std::cout << "\n--- League Standings ---\n";
    for (const auto& t : teams) {
        std::cout << t.getName() << " | Points: " << t.getPoints()
                  << " | GS: " << t.getGoalsScored()
                  << " | GC: " << t.getGoalsConceded()
                  << " | Matches: " << t.getMatchesPlayed() << '\n';
    }
}




