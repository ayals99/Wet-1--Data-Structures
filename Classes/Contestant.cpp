#include "Contestant.h"

bool Contestant::registeredInATeam() {
    for (int i = ZERO; i < NUMBER_OF_TEAMS_ALLOWED_PER_PLAYER; i++){
        if (m_teams[i] != nullptr){
            return true;
        }
    }
    return false;
}

Contestant::Contestant(int id, int countryID, Sport sport, int strength) : m_id(id), m_countryID(countryID), m_sport(sport), m_strength(strength), m_country(nullptr){
    for (int i = 0; i < NUMBER_OF_TEAMS_ALLOWED_PER_PLAYER; i++){
        m_teams[i] = nullptr;
    }
}

bool Contestant::isAvailable() {
    for (int i = 0; i < NUMBER_OF_TEAMS_ALLOWED_PER_PLAYER; ++i) {
        if (m_teams[i] == nullptr){
            return true;
        }
    }
    return false;
}

bool Contestant::isRegisteredInTeam(int teamID) {
    for (int i = 0; i < NUMBER_OF_TEAMS_ALLOWED_PER_PLAYER; ++i) {
        if (m_teams[i] != nullptr){
            if (m_teams[i]->getID() == teamID){
                return true;
            }
        }
    }
    return false;
}

void Contestant::updateStrength(int change) {
    m_strength += change;
}
