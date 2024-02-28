#ifndef WET_1_DATA_STRUCTURES_ID_H
#define WET_1_DATA_STRUCTURES_ID_H

#include "Contestant.h"
#include "Strength.h"

class Contestant;
class Strength;

class ID{
private:
    Contestant* m_contestant;
    Strength* parallel_strength;

public:
    explicit ID(Contestant* contestant) : m_contestant(contestant), parallel_strength(nullptr){};
    ID(Contestant* contestant, Strength* parallel) : m_contestant(contestant), parallel_strength(parallel){};

    int getID() const;

    Contestant* getContestant() const;

    Strength* getParallelStrength() const;

    bool operator==(const ID& other) const;
    bool operator>=(const ID& other) const;
    friend std::ostream& operator<<(std::ostream& os, const ID& id);
};


#endif //WET_1_DATA_STRUCTURES_ID_H
