#ifndef WET_1_DATA_STRUCTURES_COUNTRY_H
#define WET_1_DATA_STRUCTURES_COUNTRY_H

class Country{
private:
    int m_countryID;
    int m_numberOfContestants;
    int m_numberOfTeams;
    int m_medals;

public:
    Country(int id) : m_countryID(id), m_numberOfContestants(0), m_numberOfTeams(0){};

    int getID() const{
        return m_countryID;
    }

    void addMedal(){
        m_medals++;
    }

};
#endif //WET_1_DATA_STRUCTURES_COUNTRY_H
