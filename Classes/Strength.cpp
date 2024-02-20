//
// Created by ayals on 2/20/2024.
//
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
void Strength::setPosition(subtreePosition position){
    m_position = position;
}

bool Strength::operator>= (const Strength* other) const{
    if (this->m_contestant->getStrength() == other->m_contestant->getStrength()){
        if (this->m_contestant->getId() >= other->m_contestant->getId()){
            return true;
        }
        else{
            return false;
        }
    }
    else if (this->m_contestant->getStrength() > other->m_contestant->getStrength()){
        return true;
    }
    else{
        return false;
    }
}

bool Strength::operator == (const Strength* other) const{
    if (this >= other && other >= this){
        return true;
    }
    else{
        return false;

    }
}