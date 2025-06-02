#ifndef CARDS_H
#define CARDS_H

#include "Players.h"

class Cards {
private:
    Player* player;
    int yellowCards;
    int redCards;

public:
    explicit Cards(Player* player);

    void giveYellowCard();
    void giveRedCard();

    int getYellowCards() const;
    int getRedCards() const;
    Player* getPlayer() const;
};

#endif
