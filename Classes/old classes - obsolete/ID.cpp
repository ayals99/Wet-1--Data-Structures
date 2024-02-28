#include "ID.h"
#include "Strength.h"
#include "Contestant.h"

int ID::getID() const{
    return m_contestant->getID();
}

Contestant* ID::getContestant() const{
    return m_contestant;
}

Strength* ID::getParallelStrength() const{
    return parallel_strength;
}

bool ID::operator==(const ID& other) const{
    if (this->m_contestant->getID() == other.m_contestant->getID()){
        return true;
    }
    else{
        return false;
    }
}
bool ID::operator>=(const ID& other) const{
    if (this->m_contestant->getID() >= other.m_contestant->getID()){
        return true;
    }
    else{
        return false;
    }
}

std::ostream &operator<<(std::ostream &os, const ID &id) {
    os << "Contestant ID: " << id.m_contestant->getID() << std::endl;
    return os;
}

