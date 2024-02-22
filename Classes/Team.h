#ifndef WET_1_DATA_STRUCTURES_TEAM_H
#define WET_1_DATA_STRUCTURES_TEAM_H

#include "wet1util.h"
#include "Contestant.h"
#include "AVL_Tree.h"
#include "ID.h"
#include "Strength.h"

class Team{
private:
    int m_id;
    int m_countryID;
    Sport m_sport;
    int m_strength;
    int m_size;

    AVL_Tree<ID>* m_LEFT_ID_Tree;
    AVL_Tree<ID>* m_MIDDLE_ID_Tree;
    AVL_Tree<ID>* m_RIGHT_ID_Tree;

    AVL_Tree<Strength>* m_LEFT_Strength_Tree;
    AVL_Tree<Strength>* m_MIDDLE_Strength_Tree;
    AVL_Tree<Strength>* m_RIGHT_Strength_Tree;

public:
    Team() = default;

//        void balanceTrees(){
//      psuedo-code;
//      check if number of contestants in each tree is 0 mod3
//            if it isn't, return.
//    }

    int getID() const{
        return m_id;
    }

//    StatusType insertContestant(Contestant* contestantToRegister){// O(log n)
//        Pseudo-code;
//        Strength* strength = new Strength(contestantToRegister, UNASSIGNED);
//        ID* id = new ID(contestantToRegister, strength);
//        assignInSubtrees(id, strength); // a lot of if statements
//        balanceTrees();
//    }

//    void assignInSubtrees(id,strength){

//       TODO: add the rest of the pseudo-code with all the if statements
//       Psuedo-code:
//        int max_left = m_LEFT_ID_Tree->find_Minimum_In_Subtree()->getContestantID;
//        int max_middle = m_MIDDLE_ID_Tree->find_Minimum_In_Subtree()->getContestantID;
//
//        if (id->getContestantID() < max_left){
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
//    }
};


#endif //WET_1_DATA_STRUCTURES_TEAM_H
