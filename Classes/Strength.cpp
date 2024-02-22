#include "Strength.h"

int Strength::getId() const{
    return m_contestant->getId();
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

//bool Strength::operator>= (const Strength& other) const{
//
//}
//
//bool Strength::operator == (const Strength& other) const{
//
//}