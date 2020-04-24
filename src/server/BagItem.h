/**
 * \file BagItem.h
 */

#ifndef BagItem_h
#define BagItem_h

#include "BagObject.h"
#include "Characteristics.h"

class BagItem: public BagObject {
  private:
  protected:
  public:
    int itemType;
    Characteristics charac;

  public:
    BagItem(const int& id, const int& weight, const int& type, Characteristics c):
        BagObject (id, weight, 1), itemType(type), charac(c)
    {
    }
    // Public methods

    /**
     *  @param other TBD
     *  @return bool
     */
    bool operator==(const BagItem& other) const {
      return BagObject::operator==(other) && itemType == other.itemType && charac == other.charac;
    }


  // Protected methods
  protected:

  // Private methods
  private:
};

#endif // BagItem_h
