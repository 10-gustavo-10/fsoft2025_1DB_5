#include "headers/controllers/ChampionshipController.h"
#include "headers/views/View.h"
#include "headers/model/Team.h"
#include "headers/model/Referee.h"
#include "headers/model/Stadium.h"
#include <memory>

int main() {
    ChampionshipController controller;

    controller.getLeague().addTeam(new Team("Arouca"));
    controller.getLeague().addTeam(new Team("AVS"));
    controller.getLeague().addTeam(new Team("Benfica"));
    controller.getLeague().addTeam(new Team("Boavista"));
    controller.getLeague().addTeam(new Team("Braga"));
    controller.getLeague().addTeam(new Team("Casa Pia"));
    controller.getLeague().addTeam(new Team("Estoril"));
    controller.getLeague().addTeam(new Team("Estrela da Amadora"));
    controller.getLeague().addTeam(new Team("Famalicao"));
    controller.getLeague().addTeam(new Team("Farense"));
    controller.getLeague().addTeam(new Team("Gil Vicente"));
    controller.getLeague().addTeam(new Team("Moreirense"));
    controller.getLeague().addTeam(new Team("Nacional"));
    controller.getLeague().addTeam(new Team("Porto"));
    controller.getLeague().addTeam(new Team("Rio Ave"));
    controller.getLeague().addTeam(new Team("Santa Clara"));
    controller.getLeague().addTeam(new Team("Sporting"));
    controller.getLeague().addTeam(new Team("Vitoria SC"));

    View::menu(controller);

    return 0;
}
