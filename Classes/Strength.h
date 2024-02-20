//
// Created by ayals on 2/20/2024.
//

#ifndef WET_1_DATA_STRUCTURES_STRENGTH_H
#define WET_1_DATA_STRUCTURES_STRENGTH_H
#include "Contestant.h"

enum subtreePosition {UNASSIGNED, LEFT, MIDDLE, RIGHT};

class Strength {
private:
    Contestant* m_contestant;
    subtreePosition m_position;

public:
    Strength(Contestant* contestant, subtreePosition position) : m_contestant(contestant), m_position(UNASSIGNED){};
    int getId() const;
    int getStrength() const;
    subtreePosition getPosition() const;
    void setPosition(subtreePosition position);

    bool operator>= (const Strength* other) const;
    bool operator == (const Strength* other) const;
};


#endif //WET_1_DATA_STRUCTURES_STRENGTH_H
