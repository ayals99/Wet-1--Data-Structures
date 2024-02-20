#ifndef WET_1_DATA_STRUCTURES_ID_H
#define WET_1_DATA_STRUCTURES_ID_H

#include "Contestant.h"
#include "Strength.h"

class ID{
private:
    Contestant* m_contestant;
    Strength* parallel_strength;

public:
    explicit ID(Contestant* contestant) : m_contestant(contestant), parallel_strength(nullptr){};

    bool operator==(const ID* other) const{
        if (this->m_contestant->getId() == other->m_contestant->getId()){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator>=(const ID* other) const{
        if (this->m_contestant->getId() >= other->m_contestant->getId()){
            return true;
        }
        else{
            return false;
        }
    }
};

#endif //WET_1_DATA_STRUCTURES_ID_H
