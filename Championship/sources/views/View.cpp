#include "../../headers/views/View.h"
#include "../../headers/controllers/ChampionshipController.h"
#include "../../headers/model/Referee.h"
#include "../../headers/model/Stadium.h"
#include "../../headers/model/Team.h"

#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <iomanip>

void View::menu(ChampionshipController& controller) {
    int option;

    do {
        std::cout << "\n1. Registrar resultado de partida\n";
        std::cout << "2. Mostrar classificacao\n";
        std::cout << "0. Sair\n";

        while (true) {
            std::cout << "Escolha uma opcao (0 a 2): ";
            std::cin >> option;

            if (std::cin.fail() || option < 0 || option > 2) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Erro: introduz apenas 0, 1 ou 2.\n";
            } else break;
        }

        if (option == 1) {
            const std::vector<Team*>& teams = controller.getTeams();
            int numEquipas = static_cast<int>(teams.size());

            int id1, id2, g1, g2;
            std::string refereeName, stadiumName, stadiumCity;
            int stadiumCapacity;

            std::cout << "\n--- Equipas Disponiveis ---\n";
            for (int i = 0; i < numEquipas; ++i)
                std::cout << i << " - " << teams[i]->getName() << '\n';

            while (true) {
                std::cout << "ID da equipa da casa: ";
                std::cin >> id1;
                std::cout << "ID da equipa visitante: ";
                std::cin >> id2;

                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Erro: introduz apenas números validos!\n";
                    continue;
                }

                if (id1 < 0 || id1 >= numEquipas || id2 < 0 || id2 >= numEquipas) {
                    std::cout << "Erro: os IDs validos vao de 0 a " << (numEquipas - 1) << ". Tenta novamente.\n";
                    continue;
                }

                if (id1 == id2) {
                    std::cout << "Erro: uma equipa nao pode jogar contra si mesma.\n";
                    continue;
                }

                break;
            }

            while (true) {
                std::cout << "Golos da casa: ";
                std::cin >> g1;
                std::cout << "Golos do visitante: ";
                std::cin >> g2;

                if (std::cin.fail() || g1 < 0 || g2 < 0) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Erro: os golos devem ser numeros inteiros nao negativos.\n";
                } else break;
            }

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            while (true) {
                std::cout << "Nome do arbitro: ";
                std::getline(std::cin, refereeName);
                if (refereeName.find_first_of("0123456789") != std::string::npos || refereeName.empty()) {
                    std::cout << "Erro: o nome do arbitro deve conter apenas letras.\n";
                } else break;
            }

            std::string nationality;
            while (true) {
                std::cout << "Nacionalidade do arbitro: ";
                std::getline(std::cin, nationality);
                if (nationality.find_first_of("0123456789") != std::string::npos || nationality.empty()) {
                    std::cout << "Erro: a nacionalidade deve conter apenas letras.\n";
                } else break;
            }

            while (true) {
                std::cout << "Nome do estadio: ";
                std::getline(std::cin, stadiumName);
                if (stadiumName.find_first_of("0123456789") != std::string::npos || stadiumName.empty()) {
                    std::cout << "Erro: o nome do estadio deve conter apenas letras.\n";
                } else break;
            }

            while (true) {
                std::cout << "Capacidade do estadio: ";
                std::cin >> stadiumCapacity;
                if (std::cin.fail() || stadiumCapacity <= 0) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Erro: a capacidade deve ser um numero positivo.\n";
                } else break;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            while (true) {
                std::cout << "Cidade do estadio: ";
                std::getline(std::cin, stadiumCity);
                if (stadiumCity.find_first_of("0123456789") != std::string::npos || stadiumCity.empty()) {
                    std::cout << "Erro: a cidade deve conter apenas letras.\n";
                } else break;
            }

            auto* ref = new Referee(refereeName, nationality);
            auto* stadium = new Stadium(stadiumName, stadiumCapacity, stadiumCity);

            controller.registerMatch(id1, id2, g1, g2, ref, stadium);
        }
        else if (option == 2) {
            const std::vector<Team*>& teams = controller.getTeams();
            View::showStandings(teams);
        }

    } while (option != 0);
}

void View::showStandings(const std::vector<Team*>& teams) {
    std::vector<Team*> sortedTeams = teams;

    std::sort(sortedTeams.begin(), sortedTeams.end(), [](const Team* a, const Team* b) {
        if (a->getPoints() != b->getPoints())
            return a->getPoints() > b->getPoints();
        if (a->getGoalDifference() != b->getGoalDifference())
            return a->getGoalDifference() > b->getGoalDifference();
        return a->getGoalsScored() > b->getGoalsScored();
    });

    std::cout << "\n--- Classificacao da Liga ---\n";
    std::cout << std::left << std::setw(20) << "Equipa"
              << std::setw(10) << "Pontos"
              << std::setw(10) << "GM"
              << std::setw(10) << "GS"
              << std::setw(10) << "Jogos" << "\n";
    std::cout << "-----------------------------------------------------\n";
    for (const auto& team : sortedTeams) {
        std::cout << std::left << std::setw(20) << team->getName()
                  << std::setw(10) << team->getPoints()
                  << std::setw(10) << team->getGoalsScored()
                  << std::setw(10) << team->getGoalsConceded()
                  << std::setw(10) << team->getMatchesPlayed() << '\n';
    }
}
