#ifndef WET_1_DATA_STRUCTURES_TEAM_H
#define WET_1_DATA_STRUCTURES_TEAM_H

#include "wet1util.h"
#include "Contestant.h"
#include "AVL_Tree.h"
#include "ID.h"
#include "Strength.h"

//const static int NUMBER_OF_ID_SUBTREES = 3;
const static int AUSTERITY_REMOVALS = 3;

// I added country to the include list to add the country field to the team
#include "Country.h"

static const int TEAM_STRENGTH_NOT_MOD_3 = 0;
static const int NOT_FOUND = -1;

//Added the pre declaration of the Contestant class to "avoid" circular includes
class Contestant;
class Strength;
class ID;

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
    int getAusterity() const;
    Country* getCountry() const;

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


#endif //WET_1_DATA_STRUCTURES_TEAM_H
