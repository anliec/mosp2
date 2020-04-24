/**
 * \file BagWeapon.h
 */

#ifndef BagWeapon_h
#define BagWeapon_h

#include "BagItem.h"
#include "Characteristics.h"
#include "Attack.h"

class BagWeapon: public BagItem {
  private:
  protected:
  public:
    bool twoHanded;
    Attack attack;

  public:
    BagWeapon(const int& id, const int& weight, const int& type, Characteristics c, Attack attack, bool isTwoHanded):
        BagItem(id, weight, type, c), attack(attack), twoHanded(isTwoHanded)
    {
    }
    // Public methods

    bool operator==(const BagWeapon& other) const{
        return BagItem::operator==(other) && twoHanded == other.twoHanded && attack == other.attack;
    }


  // Protected methods
  protected:

  // Private methods
  private:
};

#endif // BagWeapon_h
