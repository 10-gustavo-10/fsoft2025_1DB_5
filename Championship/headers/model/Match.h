#ifndef MATCH_H
#define MATCH_H

#include <string>
#include <bits/stl_vector.h>

#include "Team.h"

class Match {
private:
    Team* homeTeam;
    Team* awayTeam;
    int homeGoals;
    int awayGoals;
    bool played;

public:
    Match(Team* home, Team* away);

    Match(std::vector<Team>::const_reference team, std::vector<Team>::const_reference value);

    void setResult(int homeGoals, int awayGoals);
    bool isPlayed() const;

    Team* getHomeTeam() const;
    Team* getAwayTeam() const;
    int getHomeGoals() const;
    int getAwayGoals() const;
};

#endif
