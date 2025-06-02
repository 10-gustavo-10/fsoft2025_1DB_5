#include "../../headers/model/Cards.h"

Cards::Cards(Player* player)
    : player(player), yellowCards(0), redCards(0) {}

void Cards::giveYellowCard() {
    yellowCards++;
}

void Cards::giveRedCard() {
    redCards++;
}

int Cards::getYellowCards() const {
    return yellowCards;
}

int Cards::getRedCards() const {
    return redCards;
}

Player* Cards::getPlayer() const {
    return player;
}
