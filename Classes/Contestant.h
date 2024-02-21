#ifndef WET_1_DATA_STRUCTURES_CONTESTANT_H
#define WET_1_DATA_STRUCTURES_CONTESTANT_H

#include "wet1util.h"
#include "Team.h"
#include <iostream>

const static int NUMBER_OF_TEAMS_ALLOWED_PER_PERSON = 3;

class Contestant{
private:
    int m_id;
    int m_strength;
    Sport m_sport;
    int m_countryID;

public:
    Contestant(int id, int strength, Sport sport, int countryID) : m_id(id), m_strength(strength),m_sport(sport),
                                                                   m_countryID(countryID){};

    int getId() const{
        return m_id;
    }
    int getStrength() const{
        return m_strength;
    }
    Sport getSport() const{
        return m_sport;
    }
    int getCountryID() const{
        return m_countryID;
    }
    friend std::ostream& operator<<(std::ostream& os, const Contestant& contestant);
    bool operator>= (const Contestant& other) const{
        return m_id >= other.m_id;
    }
    bool operator== (const Contestant& other) const{
        return m_id == other.m_id;
    }

//    bool isInTeam(int teamID); // Checks if registered in a specific team
//    bool registeredInATeam();
//    StatusType registerWithTeam(int teamID);
//    StatusType unregisterWithTeam(int teamID);
//    bool isAvailable();
//    bool sameSport(int teamID);
//    bool sameCountry(int teamID)
//    updateRegisteredTeamsStrengths();

};

std::ostream& operator<<(std::ostream& os, const Contestant& contestant){
    os << "Contestant ID: " << contestant.m_id << ", Strength: " << contestant.m_strength << std::endl;
    return os;
}

#endif //WET_1_DATA_STRUCTURES_CONTESTANT_H
