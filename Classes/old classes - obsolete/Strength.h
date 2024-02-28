#ifndef WET_1_DATA_STRUCTURES_STRENGTH_H
#define WET_1_DATA_STRUCTURES_STRENGTH_H

#include "Team.h"

#include <iostream>

enum subtreePosition {UNASSIGNED, LEFT, MIDDLE, RIGHT};

class Contestant;

class Strength {
private:
    Contestant* m_contestant;
    subtreePosition m_position;

public:
    explicit Strength(Contestant* contestant) : m_contestant(contestant), m_position(UNASSIGNED){};
    Strength(Contestant* contestant, subtreePosition position) : m_contestant(contestant), m_position(position){};
    ~Strength() = default;

    int getID() const;
    int getStrength() const;
    subtreePosition getPosition() const;
    void setPosition(subtreePosition position);
    Contestant* getContestant() const;

    bool operator >= (const Strength& other) const;

    bool operator == (const Strength& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Strength& strength);
};



#endif //WET_1_DATA_STRUCTURES_STRENGTH_H
