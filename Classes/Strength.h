#ifndef WET_1_DATA_STRUCTURES_STRENGTH_H
#define WET_1_DATA_STRUCTURES_STRENGTH_H
#include "Contestant.h"
#include <iostream>

enum subtreePosition {UNASSIGNED, LEFT, MIDDLE, RIGHT};

class Strength {
private:
    Contestant* m_contestant;
    subtreePosition m_position;

public:
    explicit Strength(Contestant* contestant) : m_contestant(contestant), m_position(UNASSIGNED){};
    Strength(Contestant* contestant, subtreePosition position) : m_contestant(contestant), m_position(position){};
    ~Strength() = default;

    int getId() const;
    int getStrength() const;
    subtreePosition getPosition() const;
    void setPosition(subtreePosition position);

    bool operator >= (const Strength& other) const{
        if (this->m_contestant->getStrength() == other.m_contestant->getStrength()){
            if (this->m_contestant->getId() >= other.m_contestant->getId()){
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
    bool operator == (const Strength& other) const{
        if (*this >= other && other >= *this){
            return true;
        }
        else{
            return false;
        }
    }
    friend std::ostream& operator<<(std::ostream& os, const Strength& strength);
};

std::ostream& operator<<(std::ostream& os, const Strength& strength){
    os << "Contestant ID: " << strength.m_contestant->getId() << ", Strength: " << strength.m_contestant->getStrength() << std::endl;
    return os;
}

#endif //WET_1_DATA_STRUCTURES_STRENGTH_H
