#ifndef MATCH_H
#define MATCH_H

#include "Team.h"
#include "Referee.h"
#include "Stadium.h"

class Match {
private:
    Team* homeTeam;
    Team* awayTeam;
    int homeGoals;
    int awayGoals;
    bool played;
    Referee* referee;
    Stadium* stadium;

public:
    Match(Team *home, Team *away);

    Match(Team* home, Team* away, Referee* referee, Stadium* stadium);

    Match(Team * team, Team * away, int g1, int g2, Referee * ref, Stadium * stadium);

    void setResult(int homeGoals, int awayGoals);
    bool isPlayed() const;

    Team* getHomeTeam() const;
    Team* getAwayTeam() const;
    int getHomeGoals() const;
    int getAwayGoals() const;

    Referee* getReferee() const;
    Stadium* getStadium() const;
};

#endif




