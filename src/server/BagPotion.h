/**
 * \file BagPotion.h
 */

#ifndef BagPotion_h
#define BagPotion_h

#include <vector>

#include "BagObject.h"
#include "Value.h"

class BagPotion: public BagObject {
    Q_OBJECT
public:
    std::vector<Value> effects;

public:
    BagPotion(const int& id, const std::vector<Value>& effects, const int& individualWeight=1, const int& count=1):
        BagObject(id, individualWeight, count), effects(effects)
    {
        // @todo
    }
};

#endif // BagPotion_h
