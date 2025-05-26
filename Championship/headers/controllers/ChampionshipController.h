#ifndef CHAMPIONSHIPCONTROLLER_H
#define CHAMPIONSHIPCONTROLLER_H

#include "../model/League.h"
#include <iostream>
#include <limits>

class ChampionshipController {
private:
    League league;

public:
    void run();
};

#endif