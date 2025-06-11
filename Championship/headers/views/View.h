#ifndef VIEW_H
#define VIEW_H

#include <vector>
#include "../controllers/ChampionshipController.h"
#include "../model/Team.h"

class View {
public:
    static void menu(ChampionshipController& controller);
    static void showStandings(const std::vector<Team*>& teams);
};

#endif
