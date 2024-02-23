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
//            Strength* strength = new Strength(contestantToRegister, UNASSIGNED);
//            ID* id = new ID(contestantToRegister, strength);
//            assignInSubtrees(id, strength); // a lot of if statements
//            balanceTrees();
//    }

//    void assignInSubtrees(ID* id, Strength* strength){
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
//    }

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
