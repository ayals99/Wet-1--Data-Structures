#include "Strength.h"
#include "Contestant.h"

int Strength::getID() const{
    return m_contestant->getID();
}

int Strength::getStrength() const{
    return m_contestant->getStrength();
}

subtreePosition Strength::getPosition() const{
    return m_position;
}

Contestant* Strength::getContestant() const{
    return m_contestant;
}

void Strength::setPosition(subtreePosition position){
    m_position = position;
}

bool Strength::operator >= (const Strength& other) const{
    if (this->m_contestant->getStrength() == other.m_contestant->getStrength()){
        if (this->m_contestant->getID() >= other.m_contestant->getID()){
            return true;
        }
        else{
            return false;
        }
    }
    else if (this->m_contestant->getStrength() > other.m_contestant->getStrength()){
        return true;
    }
    else{
        return false;
    }
}

bool Strength::operator == (const Strength& other) const{
    if (*this >= other && other >= *this){
        return true;
    }
    else{
        return false;
    }
}

std::ostream& operator<<(std::ostream& os, const Strength& strength){
    os << "Contestant ID: " << strength.m_contestant->getID() << ", Strength: " << strength.m_contestant->getStrength() << std::endl;
    return os;
}