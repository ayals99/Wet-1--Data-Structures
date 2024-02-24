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
    ID(Contestant* contestant, Strength* parallel) : m_contestant(contestant), parallel_strength(parallel){};

    int getID() const{
        return m_contestant->getID();
    }

    Contestant* getContestant() const{
        return m_contestant;
    }

    Strength* getParallelStrength() const{
        return parallel_strength;
    }

    bool operator==(const ID& other) const{
        if (this->m_contestant->getID() == other.m_contestant->getID()){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator>=(const ID& other) const{
        if (this->m_contestant->getID() >= other.m_contestant->getID()){
            return true;
        }
        else{
            return false;
        }
    }
    friend std::ostream& operator<<(std::ostream& os, const ID& id);
};

std::ostream &operator<<(std::ostream &os, const ID &id) {
    os << "Contestant ID: " << id.m_contestant->getID() << std::endl;
    return os;
}

#endif //WET_1_DATA_STRUCTURES_ID_H
