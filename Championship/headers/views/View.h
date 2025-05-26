#ifndef VIEW_H
#define VIEW_H

#include <vector>
#include "../model/Team.h"
#include "../controllers/ChampionshipController.h"

class View {
public:
    static void menu(ChampionshipController& controller);
    static void showStandings(const std::vector<Team>& teams);
};

#endif