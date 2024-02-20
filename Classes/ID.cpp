#include "ID.h"
bool ID::operator==(const ID& other) const{
    if (this->m_contestant->getId() == other.m_contestant->getId()){
        return true;
    }
    else{
        return false;
    }
}
bool ID::operator>=(const ID& other) const{
    if (this->m_contestant->getId() >= other.m_contestant->getId()){
        return true;
    }
    else{
        return false;
    }
}
