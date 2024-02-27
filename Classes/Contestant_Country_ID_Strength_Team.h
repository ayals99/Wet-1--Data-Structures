#ifndef WET_1_DATA_STRUCTURES_CONTESTANT_COUNTRY_ID_STRENGTH_TEAM_H
#define WET_1_DATA_STRUCTURES_CONTESTANT_COUNTRY_ID_STRENGTH_TEAM_H

#include "wet1util.h"
#include "AVL_Tree.h"

static const int INITIALIZE_CONTESTANTS = 0;
static const int INITIALIZE_TEAMS = 0;
const static int AUSTERITY_REMOVALS = 3;
const static int NUMBER_OF_ID_SUBTREES = 3;
static const int TEAM_STRENGTH_NOT_MOD_3 = 0;
static const int NOT_FOUND = -1;
const static int NUMBER_OF_TEAMS_ALLOWED_PER_PLAYER = 3;

enum subtreePosition {UNASSIGNED, LEFT, MIDDLE, RIGHT};

class Contestant;
class Strength;
class ID;

class Country{
private:
    int m_countryID;
    int m_numberOfContestants;
    int m_numberOfTeams;
    int m_medals;

public:
    Country(int id, int medals) : m_countryID(id),m_medals(medals), m_numberOfContestants(INITIALIZE_CONTESTANTS), m_numberOfTeams(INITIALIZE_TEAMS){};

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

class ID{
private:
    Contestant* m_contestant;
    Strength* parallel_strength;

public:
    ID() = delete;
    ID(const ID& other) = delete;
    explicit ID(Contestant* contestant) : m_contestant(contestant), parallel_strength(nullptr){};
    explicit ID(Contestant* contestant, Strength* parallel) : m_contestant(contestant), parallel_strength(parallel){};

    int getID() const;

    Contestant* getContestant() const;

    Strength* getParallelStrength() const;

    bool operator==(const ID& other) const;
    bool operator>=(const ID& other) const;
    friend std::ostream& operator<<(std::ostream& os, const ID& id);
};

class Team{
private:


    int m_id;
    int m_countryID;
    Sport m_sport;
    int m_strength;
    int m_austerity;
    int m_size;

    Country* m_country;

    AVL_Tree<ID>* m_LEFT_ID_Tree;
    AVL_Tree<ID>* m_MIDDLE_ID_Tree;
    AVL_Tree<ID>* m_RIGHT_ID_Tree;

    AVL_Tree<Strength>* m_LEFT_Strength_Tree;
    AVL_Tree<Strength>* m_MIDDLE_Strength_Tree;
    AVL_Tree<Strength>* m_RIGHT_Strength_Tree;

    void setSize(int newSize){
        m_size = newSize;
    }

public:
    Team(int id,int countryID, Sport sport, Country* teamsCountry)
            :   m_id(id),
                m_countryID(countryID),
                m_sport(sport), m_strength(ZERO),
                m_austerity(ZERO), m_size(ZERO),
                m_country(teamsCountry),
                m_LEFT_ID_Tree(new AVL_Tree<ID>),
                m_MIDDLE_ID_Tree(new AVL_Tree<ID>),
                m_RIGHT_ID_Tree(new AVL_Tree<ID>),
                m_LEFT_Strength_Tree(new AVL_Tree<Strength>),
                m_MIDDLE_Strength_Tree(new AVL_Tree<Strength>),
                m_RIGHT_Strength_Tree(new AVL_Tree<Strength>){}

    ~Team();

    int getID() const;
    int getCountryID() const;
    Sport getSport() const;
    int getStrength() const;
    int getSize() const;
    void decrementSize();
    int getAusterity() const;
    Country* getCountry() const;

    bool printTeamInOrder(){
        std::cout<<"Team ID: "<<m_id<<std::endl;

        if (!m_LEFT_ID_Tree->printTreeInOrder()){
            return false;
        }

        std::cout<<std::endl;
        if (!m_MIDDLE_ID_Tree->printTreeInOrder()){
            return false;
        }

        std::cout<<std::endl;
        if (!m_RIGHT_ID_Tree->printTreeInOrder()){
            return false;
        }

        std::cout<<std::endl;
        if (!m_LEFT_Strength_Tree->printTreeInOrder()){
            return false;
        }

        std::cout<<std::endl;
        if (!m_MIDDLE_Strength_Tree->printTreeInOrder()){
            return false;
        }

        std::cout<<std::endl;
        if (!m_RIGHT_Strength_Tree->printTreeInOrder()){
            return false;
        }

        return true;
    }

    bool operator== (const Team& other) const{
        return m_id == other.m_id;
    }

    bool operator>= (const Team& other) const{
        return m_id >= other.m_id;
    }

    void removeContestantFromTeam(Contestant* contestant);

    void removeContestantFromSubtrees(Contestant* contestant);

    StatusType insertContestant(Contestant* contestantToRegister);

    void assignInSubtrees(ID* id, Strength* strength);

    void balanceTrees();

    StatusType mergeTeams(Team* team2);

    int calculateTeamStrength();

    void updateTeamStrength();

    int calculateAusterity();

    void updateAusterity();

    void updateMAXPossibleStrength();

    Contestant** delete_i_from_LeftTree(int i);

    Contestant** delete_j_from_MiddleTree(int j);

    Contestant** delete_k_from_RightTree(int k);

    void reInsert(Contestant** removedContestants, int amount, subtreePosition position);

    void reinsert_i_to_LeftTree(Contestant** LEFT_removedContestants, int i);

    void reinsert_j_to_MiddleTree(Contestant** MIDDLE_removedContestants, int j);

    void reinsert_k_to_RightTree(Contestant** RIGHT_removedContestants, int k);

    void removeDataFromSubtrees();

    void deleteSubtrees();

    void assignNewSubtrees(AVL_Tree<ID>* LEFT_ID_Tree,
                           AVL_Tree<ID>* MIDDLE_ID_Tree,
                           AVL_Tree<ID>* RIGHT_ID_Tree,
                           AVL_Tree<Strength>* LEFT_Strength_Tree,
                           AVL_Tree<Strength>* MIDDLE_Strength_Tree,
                           AVL_Tree<Strength>* RIGHT_Strength_Tree);

    ID** getSortedIdArray() const;

    Strength** getSortedStrengthArray() const;
};

class Contestant{
private:

    int m_id;
    int m_strength;
    Sport m_sport;
    int m_countryID;
    Country* m_country;
    Team* m_teams[NUMBER_OF_TEAMS_ALLOWED_PER_PLAYER];

public:
   explicit Contestant(int id, int countryID, Sport sport, int strength);
   Contestant() = delete;
   Contestant(const Contestant& other) = delete;

    int getID() const{
        return m_id;
    }

    Team* getTeam(int index) const{
        return m_teams[index];
    }
    void removeTeam(int index){
        m_teams[index] = nullptr;
    }
    void setTeam(int index, Team* team){
        m_teams[index] = team;
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
    Country* getCountryPointer() const{
        return m_country;
    }
    void setCountryPointer(Country* country){
        m_country = country;
    }
    friend std::ostream& operator<<(std::ostream& os, const Contestant& contestant);

    bool operator>= (const Contestant& other) const{
        return m_id >= other.m_id;
    }
    bool operator== (const Contestant& other) const{
        return m_id == other.m_id;
    }

// TODO: implement the following functions in the cpp file! otherwise it will be a circular include and we can't access members of Team
//    bool isInTeam(int teamID); // Checks if registered in a specific team
//    bool registeredInATeam();
    void registerWithTeam(Team* team);

    void unregisterWithTeam(int teamID);
//    bool isAvailable();
//    bool sameSport(int teamID);
//    bool sameCountry(int teamID)
//    updateRegisteredTeamsStrengths();


    void updateStrength(int change);
    bool registeredInATeam();
    bool isAvailable();
    bool isRegisteredInTeam(int teamID);
};

class Strength {
private:
    Contestant* m_contestant;
    subtreePosition m_position;

public:
    explicit Strength(Contestant* contestant) : m_contestant(contestant), m_position(UNASSIGNED){};
    Strength(Contestant* contestant, subtreePosition position) : m_contestant(contestant), m_position(position){};
    ~Strength() = default;

    int getID() const;
    int getStrength() const;
    subtreePosition getPosition() const;
    void setPosition(subtreePosition position);
    Contestant* getContestant() const;

    bool operator >= (const Strength& other) const;

    bool operator == (const Strength& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Strength& strength);
};

#endif //WET_1_DATA_STRUCTURES_CONTESTANT_COUNTRY_ID_STRENGTH_TEAM_H
