#include "headers/model/League.h"
#include <iostream>

int main() {
    // Criar campeonato
    League league;

    // Criar equipas
    Team* porto = new Team("FC Porto");
    Team* benfica = new Team("Benfica");
    Team* sporting = new Team("Sporting");

    // Adicionar equipas ao campeonato
    league.addTeam(porto);
    league.addTeam(benfica);
    league.addTeam(sporting);

    // Criar e registar jogos
    Match* m1 = new Match(porto, benfica);
    m1->setResult(2, 1); // FC Porto 2 - 1 Benfica
    league.addMatch(m1);

    Match* m2 = new Match(sporting, porto);
    m2->setResult(0, 3); // Sporting 0 - 3 FC Porto
    league.addMatch(m2);

    Match* m3 = new Match(benfica, sporting);
    m3->setResult(2, 2); // Benfica 2 - 2 Sporting
    league.addMatch(m3);

    // Mostrar classificação
    league.showStandings();

    return 0;
}


