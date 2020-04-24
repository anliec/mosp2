/**
 * \file MonsterTeam.h
 */

#ifndef MonsterTeam_h
#define MonsterTeam_h

#include <vector>

#include "Living.h"
#include "Monster.h"


class MonsterTeam: public Living {
    Q_OBJECT
protected:
    std::vector<Monster> monsters;

public:
    MonsterTeam(): Living()
    {
        // @todo
    }

    virtual ~MonsterTeam(){

    }

};

#endif // MonsterTeam_h
