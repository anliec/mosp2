/**
 * \file ObjectDescriptor.h
 */

#ifndef ObjectDescriptor_h
#define ObjectDescriptor_h

#include <memory>

#include "Attack.h"
#include "CharacteristicsRange.h"

class ObjectDescriptor {
  private:
  protected:
  public:
    std::shared_ptr<CharacteristicsRange> itemCharac;
    std::shared_ptr<Attack> weaponAttack;
    int objectWeight;

  public:
    ObjectDescriptor()
    {
      // @todo
    }
    // Public methods


  // Protected methods
  protected:

  // Private methods
  private:
};

#endif // ObjectDescriptor_h
