/**
 * \file FightEndResult.h
 */

#ifndef FightEndResult_h
#define FightEndResult_h

#include <vector>

#include "BagObject.h"

class FightEndResult {
private:
protected:
public:
    bool win;
    std::vector<BagObject> drop;
    int experience;

public:
    FightEndResult()
    {
        // @todo
    }
    // Public methods


    // Protected methods
protected:

    // Private methods
private:
};

#endif // FightEndResult_h
