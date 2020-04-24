/**
 * \file StorageObject.h
 */

#ifndef StorageObject_h
#define StorageObject_h

#include <vector>
#include <memory>

#include "InteractiveObject.h"
#include "BagObject.h"

class StorageObject: public InteractiveObject {
    Q_OBJECT
protected:
    std::vector<std::shared_ptr<BagObject>> storage;

public:
    StorageObject(): InteractiveObject()
    {
        // @todo
    }
};

#endif // StorageObject_h
