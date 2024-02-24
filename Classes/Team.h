#ifndef WET_1_DATA_STRUCTURES_TEAM_H
#define WET_1_DATA_STRUCTURES_TEAM_H

#include "wet1util.h"
#include "Contestant.h"
#include "AVL_Tree.h"
#include "ID.h"
#include "Strength.h"

// I added country to the include list to add the country field to the team
#include "Country.h"

static const int TEAM_STRENGTH_NOT_MOD_3 = 0;
static const int THREE = 3;

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
    Team(int id,int countryID, Sport sport, Country* teamsCountry) : m_id(id),
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



    int getID() const{
        return m_id;
    }
    int getCountryID() const{
        return m_countryID;
    }
    Sport getSport() const{
        return m_sport;
    }
    int getStrength() const{
        return m_strength;
    }
    int getSize() const{
        return m_size;
    }
    int getAusterity() const{
        return m_austerity;
    }
    Country* getCountry() const{
        return m_country;
    }

    bool operator== (const Team& other) const{
        return m_id == other.m_id;
    }
    bool operator>= (const Team& other) const{
        return m_id >= other.m_id;
    }

//        void balanceTrees(){
//      psuedo-code;
//      check if number of contestants in each tree is 0 mod3
//            if it isn't, return.
//    }

    StatusType insertContestant(Contestant* contestantToRegister){// O(log n)
//        Pseudo-code;
//            Strength* strength = new Strength(contestantToRegister, UNASSIGNED);
//            ID* id = new ID(contestantToRegister, strength);
//            assignInSubtrees(id, strength); // a lot of if statements
//            balanceTrees();
            }

    void assignInSubtrees(ID* id, Strength* strength) {
//       Psuedo-code:
//        int max_left_ID = m_LEFT_ID_Tree->find_Maximum_In_Subtree()->getContestantID;
//        int max_middle_ID = m_MIDDLE_ID_Tree->find_Maximum_In_Subtree()->getContestantID;
//
//        if (id->getContestantID() < max_left_ID){
//            m_LEFT_ID_Tree->insert(id);
//            strength->setPosition(LEFT);
//            m_LEFT_Strength_Tree->insert(strength);
//        }
//        else if (id->getContestantID() < max_middle){
//            m_MIDDLE_ID_Tree->insert(id);
//            strength->setPosition(MIDDLE);
//            m_MIDDLE_Strength_Tree->insert(strength);
//        }
//        else{
//            m_RIGHT_ID_Tree->insert(id);
//            strength->setPosition(RIGHT);
//            m_RIGHT_Strength_Tree->insert(strength);
//        }
//        m_size++;

    }

//    void balanceTrees(){ // (1)
//        if (this->m_size % 3 != 0){
//            return;
//        }
//        int left_size = m_LEFT_ID_Tree->getSize();
//        int middle_size = m_MIDDLE_ID_Tree->getSize();
//        int right_size = m_RIGHT_ID_Tree->getSize();
//
//      if (left size - middle size == 1 && left size - right size == 2){
//        {
//          tranfer largest in left tree to middle
//          then transfer largest in middle to right
//        }
//      if (left size - middle size == 3 && left size - right size == 3){
//        transfer two from left to middle
//        then trasfer one from middle to right
//      }
//      if (left size - middle size == 2 && left size - right size == 1){
//          transfer largest in left to middle
//      }

//      if (middle size - left size == 1 && middle size - right size == 2){
//        transfer largest in middle to right
//      }
//      if (middle size - left size == 3 && middle size - right size == 3){
//       transfer largest in middle to right
//       transfer smallest in middle to left
//      }
//     if (middle size - left size == 2 && middle size - right size == 1){
//       transfer smallest in middle to left
//     }

//     if (right size - left size == 1 && right size - middle size == 2){
//       transfer smallest in right to middle
//     }
//     if (right size - left size == 3 && right size - middle size == 3){
//      transfer two smallest from right to middle
//      transfer smallest from middle to left
//     }
//     if (right size - left size == 2 && right size - middle size == 1){
//      transfer smallest in right to middle
//      transfer smallest in middle to left
//     }
//}



    int calculateTeamStrength(){
        int teamStrength = TEAM_STRENGTH_NOT_MOD_3;
        if (this->getSize() % 3 != 0){
            return teamStrength;
        }

        teamStrength += m_LEFT_Strength_Tree->find_Maximum_In_Subtree()->getStrength();
        teamStrength += m_MIDDLE_Strength_Tree->find_Maximum_In_Subtree()->getStrength();
        teamStrength += m_RIGHT_Strength_Tree->find_Maximum_In_Subtree()->getStrength();

        return teamStrength;
    }

     void updateTeamStrength(){
        m_strength = calculateTeamStrength();
     }

    const static int NUMBER_OF_ID_SUBTREES = 3;
    const static int AUSTERITY_REMOVALS = 3;

    void updateAusterity(){
        int maxPossibleStrength = ZERO;
// Pseudocode:
//        for (int i = 0; i < AUSTERITY_REMOVALS; i++){ // LEFT_SUBTREE
//
//            // remove i contestants from the left subtree, while saving their Contestant* in an array in order to use insterContestant later on to reinsert them. make sure to use m_size-- after every removal
//
//            for (int j = 0 < AUSTERITY_REMOVALS - i; j++){ // MIDDLE_SUBTREE
//
///                // remove j contestants from the middle subtree
///                // while saving their Contestant* in an array
///                // in order to use insterContestant later on to reinsert them.
///                // make sure to use m_size-- after every removal
///
///                // add two cases here: if (j == 1 && i == 2) OR (j == 1 && i == 0, because then k == 2)
///                     // in these two cases:
///                             remove the smallestStrength in middle tree
///                             check the strength
///                             save the second to smallestStrength in a Contestant* temp
///                             re-insert the Contestant(smallestStrength)
///                             remove the smallest strength
///                             check the strength
///                             re-insert the Contestant(temp)

//                int k = AUSTERITY_REMOVALS - i - j;
//
///                // remove k contestants from the right subtree while saving their Contestant* in an array in order to use insterContestant later on to reinsert them. make sure to use m_size-- after every removal
//
//                int currentStrength = calculateTeamStrength();
//                if (calculateTeamStrength() > maxPossibleStrength){
//
//
//                    if (currentStrength > maxPossibleStrength){
//                        maxPossibleStrength = currentStrength;
//                    }
//
//                }
//
//              // insert all k contestants in the array back to the right subtree, using insertContestant

//              // insert all j contestants in the array back to the middle subtree, using insertContestant
//            }
//
//        }
//        // insert i contestants back to the left subtree
//        m_austerity = maxPossibleStrength;
    }

void updateMAXPossibleStrength(){
    int currentAusterityStrength = calculateTeamStrength();
    if (currentAusterityStrength > m_austerity){
        m_austerity = currentAusterityStrength;
    }
}

Contestant** delete_i_from_LeftTree(int i){
    Contestant** LEFT_removedContestants = new Contestant*[AUSTERITY_REMOVALS];
    for (int t = 0; t < i; t++){
        ID* removedID = m_LEFT_ID_Tree->find_Minimum_In_Subtree();
        Strength* removedStrength = removedID->getParallelStrength();
        m_LEFT_ID_Tree->remove(removedID);
        m_LEFT_Strength_Tree->remove(removedStrength);
        m_size--;
    }
    return LEFT_removedContestants;
}

Contestant** delete_j_from_MiddleTree(int j){
    Contestant** MIDDLE_removedContestants = new Contestant*[AUSTERITY_REMOVALS];
    for (int m = 0; m < j; m++){
        ID* removedID_MIDDLE = m_MIDDLE_ID_Tree->find_Minimum_In_Subtree();
        MIDDLE_removedContestants[m] = removedID_MIDDLE->getContestant();
        Strength* removedStrength = removedID_MIDDLE->getParallelStrength();
        m_MIDDLE_ID_Tree->remove(removedID_MIDDLE);
        m_MIDDLE_Strength_Tree->remove(removedStrength);
        m_size--;
    }
    return MIDDLE_removedContestants;
}

Contestant** delete_k_from_RightTree(int k){
    Contestant** RIGHT_removedContestants = new Contestant*[AUSTERITY_REMOVALS];
    for (int n = 0; n < k; n++){
        ID* removedID = m_RIGHT_ID_Tree->find_Minimum_In_Subtree();
        RIGHT_removedContestants[n] = removedID->getContestant();
        Strength* removedStrength = removedID->getParallelStrength();
        m_RIGHT_ID_Tree->remove(removedID);
        m_RIGHT_Strength_Tree->remove(removedStrength);
        m_size--;
    }
    return RIGHT_removedContestants;
}

    void reinsert_i_to_LeftTree(Contestant** LEFT_removedContestants, int i){
        for(int t = 0; t < i; t++){
            this->insertContestant(LEFT_removedContestants[t]);
        }
    }

    void reinsert_j_to_MiddleTree(Contestant** MIDDLE_removedContestants, int j){
        for(int m = 0; m < j; m++){
            this->insertContestant(MIDDLE_removedContestants[m]);
        }
    }

    void reinsert_k_to_RightTree(Contestant** RIGHT_removedContestants, int k){
        for (int n = 0; n < k; n++){
            this->insertContestant(RIGHT_removedContestants[n]);
        }
    }




    void removeDataFromSubtrees(){
        m_LEFT_ID_Tree->removeDataFromTree();
        m_MIDDLE_ID_Tree->removeDataFromTree();
        m_RIGHT_ID_Tree->removeDataFromTree();
        m_LEFT_Strength_Tree->removeDataFromTree();
        m_MIDDLE_Strength_Tree->removeDataFromTree();
        m_RIGHT_Strength_Tree->removeDataFromTree();
    }
    void deleteSubtrees(){
        delete m_LEFT_ID_Tree;
        delete m_MIDDLE_ID_Tree;
        delete m_RIGHT_ID_Tree;
        delete m_LEFT_Strength_Tree;
        delete m_MIDDLE_Strength_Tree;
        delete m_RIGHT_Strength_Tree;
    }
    void assignNewSubtrees(AVL_Tree<ID>* LEFT_ID_Tree,
                           AVL_Tree<ID>* MIDDLE_ID_Tree,
                           AVL_Tree<ID>* RIGHT_ID_Tree,
                           AVL_Tree<Strength>* LEFT_Strength_Tree,
                           AVL_Tree<Strength>* MIDDLE_Strength_Tree,
                           AVL_Tree<Strength>* RIGHT_Strength_Tree){
        m_LEFT_ID_Tree = LEFT_ID_Tree;
        m_MIDDLE_ID_Tree = MIDDLE_ID_Tree;
        m_RIGHT_ID_Tree = RIGHT_ID_Tree;
        m_LEFT_Strength_Tree = LEFT_Strength_Tree;
        m_MIDDLE_Strength_Tree = MIDDLE_Strength_Tree;
        m_RIGHT_Strength_Tree = RIGHT_Strength_Tree;
    }

};


#endif //WET_1_DATA_STRUCTURES_TEAM_H
