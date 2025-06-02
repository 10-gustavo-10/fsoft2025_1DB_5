#ifndef CHAMPIONSHIPCONTROLLER_H
#define CHAMPIONSHIPCONTROLLER_H

#include "../model/League.h"

class ChampionshipController {
private:
    League league;


public:
    void run();
    const std::vector<Team*>& getTeams() const;
    void registerMatch(int id1, int id2, int g1, int g2, Referee* ref, Stadium* stadium);
    League& getLeague();

};

#endif
