/**
 * \file Monster.h
 */

#ifndef Monster_h
#define Monster_h

#include <vector>

#include "Living.h"
#include "DropItem.h"


class Monster: public Living {
    Q_OBJECT
protected:
    int monsterClass;
    std::vector<DropItem> drop;
public:
    Monster(): Living()
    {
        // @todo
    }

};

#endif // Monster_h
