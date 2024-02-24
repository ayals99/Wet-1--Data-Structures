#ifndef WET_1_DATA_STRUCTURES_COUNTRY_H
#define WET_1_DATA_STRUCTURES_COUNTRY_H

static const int INITILIAZE_CONTESTANTS = 0;
static const int INITILIAZE_TEAMS = 0;

class Country{
private:
    int m_countryID;
    int m_numberOfContestants;
    int m_numberOfTeams;
    int m_medals;

public:
    Country(int id, int medals) : m_countryID(id),m_medals(medals), m_numberOfContestants(INITILIAZE_CONTESTANTS), m_numberOfTeams(INITILIAZE_TEAMS){};

    int getID() const{
        return m_countryID;
    }

    void addMedal(){
        m_medals++;
    }

    void addMedals(int medals){
        m_medals += medals;
    }

    int getMedals() const{
        return m_medals;
    }

    int getTeamCounter() const{
        return m_numberOfTeams;
    }

    int getContestantCounter() const{
        return m_numberOfContestants;
    }

    void decreaseTeamCounter(){
        m_numberOfTeams--;
    }

    void decreaseContestantCounter(){
        m_numberOfContestants--;
    }

    void increaseTeamCounter(){
        m_numberOfTeams++;
    }

    void increaseContestantCounter(){
        m_numberOfContestants++;
    }

    bool operator== (const Country& other) const{
        return m_countryID == other.m_countryID;
    }

    bool operator>= (const Country& other) const{
        return m_countryID >= other.m_countryID;
    }


};
#endif //WET_1_DATA_STRUCTURES_COUNTRY_H
