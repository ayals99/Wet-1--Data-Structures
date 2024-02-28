#ifndef WET_1_DATA_STRUCTURES_CONTESTANT_LIAISON_H
#define WET_1_DATA_STRUCTURES_CONTESTANT_LIAISON_H

#include "AVL_Node.h"
#include "../Classes/Contestant.h"
#include <memory>

enum SubTreePosition {LEFT, MIDDLE, RIGHT};

template <class T>
class Contestant_Liaison {
protected:
    std::shared_ptr<Contestant> m_contestant;
    Contestant_Liaison* parallel_Liaison;
};


template <class T>
class Contestant_Liaison_AVL : public Contestant_Liaison<T>{
private:
    AVL_Node<T>* parallel_In_Tree;
};

template <class T>
class Contestant_Liaison_Array : public Contestant_Liaison<T>{
private:
    SubTreePosition m_position;
};

#endif //WET_1_DATA_STRUCTURES_CONTESTANT_LIAISON_H
