/**
 * \file AttackDamage.h
 */

#ifndef AttackDamage_h
#define AttackDamage_h

#include <vector>

#include "Value.h"
#include "Effect.h"


class AttackDamage {
  private:
  protected:
  public:
    int attackId;
    std::vector<Value> damages;
    std::vector<Effect> effects;

  public:
    AttackDamage(const int& attackId, std::vector<Value> damage, std::vector<Effect> effects):
        attackId(attackId), damages(damage), effects(effects)
    {

    }
    // Public methods


  // Protected methods
  protected:

  // Private methods
  private:
};

#endif // AttackDamage_h
