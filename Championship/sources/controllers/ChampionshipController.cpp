#include "../../headers/controllers/ChampionshipController.h"
#include <iostream>
#include <limits>

const std::vector<Team*>& ChampionshipController::getTeams() const {
    return league.getTeams();
}

void ChampionshipController::registerMatch(const int id1, const int id2, const int g1, const int g2, Referee* ref, Stadium* stadium) {
    const std::vector<Team*>& teams = league.getTeams();

    if (id1 < 0 || id1 >= static_cast<int>(teams.size()) || id2 < 0 || id2 >= static_cast<int>(teams.size()) || id1 == id2) {
        std::cerr << "IDs invalidos de equipa.\n";
        return;
    }

    Team* home = teams[id1];
    Team* away = teams[id2];

    auto* match = new Match(home, away, g1, g2, ref, stadium);
    league.addMatch(match);
}

League & ChampionshipController::getLeague() {
    return league;
}


void ChampionshipController::run() {
    int opcao;
    int numEquipas;

    std::cout << "Quantas equipas queres adicionar? ";
    std::cin >> numEquipas;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < numEquipas; ++i) {
        std::string nome;
        std::cout << "Nome da equipa #" << (i + 1) << ": ";
        std::getline(std::cin, nome);
        league.addTeam(new Team(nome));
    }

    do {
        std::cout << "\n=== Menu ===\n";
        std::cout << "1. Adicionar jogo\n";
        std::cout << "2. Ver classificacao\n";
        std::cout << "0. Sair\n";
        std::cout << "Opcao: ";
        std::cin >> opcao;

        if (opcao == 1) {
            int homeIdx, awayIdx, golosCasa, golosFora;
            std::cout << "\nLista de equipas:\n";
            for (size_t i = 0; i < league.getTeams().size(); ++i) {
                std::cout << i << ". " << league.getTeams()[i]->getName() << "\n";
            }

            std::cout << "Indice da equipa da casa: ";
            std::cin >> homeIdx;
            std::cout << "Indice da equipa visitante: ";
            std::cin >> awayIdx;

            std::cout << "Golos da equipa da casa: ";
            std::cin >> golosCasa;
            std::cout << "Golos da equipa visitante: ";
            std::cin >> golosFora;

            if (homeIdx != awayIdx &&
                homeIdx >= 0 && homeIdx < static_cast<int>(league.getTeams().size()) &&
                awayIdx >= 0 && awayIdx < static_cast<int>(league.getTeams().size())) {
                auto* match = new Match(league.getTeams()[homeIdx], league.getTeams()[awayIdx]);
                match->setResult(golosCasa, golosFora);
                league.addMatch(match);
                std::cout << "Jogo registado com sucesso!\n";
            } else {
                std::cout << "Erro: indice invalido ou equipas iguais.\n";
            }

        } else if (opcao == 2) {
            league.showStandings();
        }
    }



    while (opcao != 0);


    std::cout << "Encerrando aplicacao...\n";
}


