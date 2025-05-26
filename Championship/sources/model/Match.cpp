#include "../../headers/model/Match.h"

Match::Match(Team* home, Team* away)
        : homeTeam(home), awayTeam(away), homeGoals(0), awayGoals(0), played(false) {}

void Match::setResult(int hg, int ag) {
    if (!played) {
        homeGoals = hg;
        awayGoals = ag;
        homeTeam->updateStats(hg, ag);
        awayTeam->updateStats(ag, hg);
        played = true;
    }
}

bool Match::isPlayed() const {
    return played;
}

Team* Match::getHomeTeam() const {
    return homeTeam;
}

Team* Match::getAwayTeam() const {
    return awayTeam;
}

int Match::getHomeGoals() const {
    return homeGoals;
}

int Match::getAwayGoals() const {
    return awayGoals;
}
