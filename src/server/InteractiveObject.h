/**
 * \file InteractiveObject.h
 */

#ifndef InteractiveObject_h
#define InteractiveObject_h

#include <vector>

#include "MapObject.h"
#include "Action.h"

class InteractiveObject: public MapObject {
    Q_OBJECT
protected:
    std::vector<Action> possibleActions;

public:
    InteractiveObject(): MapObject()
    {
        // @todo
    }
    // Public methods

    /**
     *  @return bool
     */
    bool blockView() const {
        // @todo
    }

    /**
     *  @return bool
     */
    bool useTile() const {
        // @todo
    }
};

#endif // InteractiveObject_h
