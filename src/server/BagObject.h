/**
 * \file BagObject.h
 */

#ifndef BagObject_h
#define BagObject_h

#include "MapObject.h"

class BagObject: public MapObject {
    Q_OBJECT
protected:
    int individualWeight;
public:
    int itemId;
    int itemCount;

public:
    BagObject(const int& id, const int& individualWeight=1, const int& count=1):
        individualWeight(individualWeight), itemId(id), itemCount(count)
    {
        // @todo
    }
    // Public methods

    /**
     *  @return int
     */
    int getWeight() const {
        return individualWeight * itemCount;
    }

    /**
     *  @param other TBD
     *  @return bool
     */
    bool operator==(const BagObject& other) const {
        return other.itemId == itemId;
    }
};

#endif // BagObject_h
