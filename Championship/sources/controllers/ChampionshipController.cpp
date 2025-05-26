#include "../../headers/controllers/ChampionshipController.h"

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
        std::cout << "2. Ver classificação\n";
        std::cout << "0. Sair\n";
        std::cout << "Opção: ";
        std::cin >> opcao;

        if (opcao == 1) {
            int homeIdx, awayIdx, golosCasa, golosFora;
            std::cout << "\nLista de equipas:\n";
            for (size_t i = 0; i < league.getTeams().size(); ++i) {
                std::cout << i << ". " << league.getTeams()[i].getName() << "\n";
            }

            std::cout << "Índice da equipa da casa: ";
            std::cin >> homeIdx;
            std::cout << "Índice da equipa visitante: ";
            std::cin >> awayIdx;

            std::cout << "Golos da equipa da casa: ";
            std::cin >> golosCasa;
            std::cout << "Golos da equipa visitante: ";
            std::cin >> golosFora;

            if (homeIdx != awayIdx &&
                homeIdx >= 0 && homeIdx < (int)league.getTeams().size() &&
                awayIdx >= 0 && awayIdx < (int)league.getTeams().size()) {
                auto* match = new Match(league.getTeams()[homeIdx], league.getTeams()[awayIdx]);
                match->setResult(golosCasa, golosFora);
                league.addMatch(match);
                std::cout << "Jogo registado com sucesso!\n";
            } else {
                std::cout << "Erro: índice inválido ou equipas iguais.\n";
            }

        } else if (opcao == 2) {
            league.showStandings();
        }

    } while (opcao != 0);

    std::cout << "Encerrando aplicação...\n";
}