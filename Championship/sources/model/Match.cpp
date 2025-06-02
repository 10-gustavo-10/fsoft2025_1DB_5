#include "../../headers/model/Match.h"

Match::Match(Team* home, Team* away)
    : homeTeam(home), awayTeam(away), homeGoals(0), awayGoals(0),
      played(false), referee(nullptr), stadium(nullptr) {}

Match::Match(Team* home, Team* away, Referee* referee, Stadium* stadium)
    : homeTeam(home), awayTeam(away), homeGoals(0), awayGoals(0),
      played(false), referee(referee), stadium(stadium) {}

Match::Match(Team* home, Team* away, int g1, int g2, Referee* ref, Stadium* stadium)
    : homeTeam(home), awayTeam(away), homeGoals(g1), awayGoals(g2),
      played(true), referee(ref), stadium(stadium) {

    homeTeam->updateStats(g1, g2);
    awayTeam->updateStats(g2, g1);
}

void Match::setResult(const int homeGoals, const int awayGoals) {
    if (!played) {
        homeTeam->updateStats(homeGoals, awayGoals);
        awayTeam->updateStats(awayGoals, homeGoals);
        this->homeGoals = homeGoals;
        this->awayGoals = awayGoals;
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

Referee* Match::getReferee() const {
    return referee;
}

Stadium* Match::getStadium() const {
    return stadium;
}
