#ifndef LEAGUE_H
#define LEAGUE_H

#include <vector>
#include <string>
#include <algorithm>
#include "Team.h"
#include "Match.h"

class League {
private:
    std::vector<Team*> teams;
    std::vector<Match*> matches;

public:
    ~League();

    void addTeam(Team* team);               // Adiciona uma equipa ao campeonato
    void addMatch(Match* match);            // Adiciona um jogo ao campeonato
    void showStandings() const;             // Mostra a tabela classificativa
    const std::vector<Team*>& getTeams() const; // Permite aceder à lista de equipas
    const std::vector<Match*>& getMatches() const; // (Opcional) Aceder aos jogos
};

#endif