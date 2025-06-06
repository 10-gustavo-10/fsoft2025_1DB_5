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

    void addTeam(Team* team);
    void addMatch(Match* match);
    void showStandings() const;
    const std::vector<Team*>& getTeams() const;
    const std::vector<Match*>& getMatches() const;
};

#endif