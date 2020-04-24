/**
 * \file Character.h
 */

#ifndef Character_h
#define Character_h

#include <memory>

#include "Living.h"
#include "BagItem.h"
#include "BagWeapon.h"


class Character: public Living {
    Q_OBJECT
  private:
  protected:
    std::shared_ptr<BagItem> hat;
    std::shared_ptr<BagItem> footWear;
    std::shared_ptr<BagItem> belt;
    std::shared_ptr<BagItem> necklace;
    std::shared_ptr<BagItem> ring1;
    std::shared_ptr<BagItem> ring2;
    std::shared_ptr<BagWeapon> hand1;
    std::shared_ptr<BagWeapon> hand2;
  public:

  public:
    Character(): Living()
    {
      // @todo
    }
    // Public methods


  // Protected methods
  protected:

  // Private methods
  private:
};

#endif // Character_h
