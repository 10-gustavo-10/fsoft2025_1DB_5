
#include "../../headers/views/View.h"
#include "../../headers/controllers/ChampionshipController.h"
#include "../../headers/model/Referee.h"
#include "../../headers/model/Stadium.h"
#include "../../headers/model/Team.h"

#include <iostream>
#include <limits>
#include <string>

void View::menu(ChampionshipController& controller) {
    int option;

    do {
        std::cout << "\n1. Registrar resultado de partida\n";
        std::cout << "2. Mostrar classificacao\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> option;

        if (option == 1) {
            const std::vector<Team*>& teams = controller.getTeams();

            int id1, id2, g1, g2;
            std::string refereeName, stadiumName, stadiumCity;
            int stadiumCapacity;

            std::cout << "\n--- Equipas Disponiveis ---\n";
            for (size_t i = 0; i < teams.size(); ++i) {
                std::cout << i << " - " << teams[i]->getName() << '\n';
            }

            std::cout << "ID da equipa da casa: ";
            std::cin >> id1;
            std::cout << "ID da equipa visitante: ";
            std::cin >> id2;
            std::cout << "Golos da casa: ";
            std::cin >> g1;
            std::cout << "Golos do visitante: ";
            std::cin >> g2;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpa buffer

            std::cout << "Nome do arbitro: ";
            std::getline(std::cin, refereeName);

            std::string nationality;
            std::cout << "Nacionalidade do arbitro: ";
            std::getline(std::cin, nationality);

            std::cout << "Nome do estadio: ";
            std::getline(std::cin, stadiumName);

            std::cout << "Capacidade do estadio: ";
            std::cin >> stadiumCapacity;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Cidade do estadio: ";
            std::getline(std::cin, stadiumCity);


            Referee* ref = new Referee(refereeName, nationality);
            Stadium* stadium = new Stadium(stadiumName, stadiumCapacity, stadiumCity);

            controller.registerMatch(id1, id2, g1, g2, ref, stadium);
        }
        else if (option == 2) {
            const std::vector<Team*>& teams = controller.getTeams();
            showStandings(teams);
        }

    } while (option != 0);
}

void View::showStandings(const std::vector<Team*>& teams) {
    std::cout << "\n--- Classificacao da Liga ---\n";
    for (const auto& team : teams) {
        std::cout << team->getName() << " | Pontos: " << team->getPoints()
                  << " | GM: " << team->getGoalsScored()
                  << " | GS: " << team->getGoalsConceded()
                  << " | Jogos: " << team->getMatchesPlayed() << '\n';
    }
}





