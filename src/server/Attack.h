/**
 * \file Attack.h
 */

#ifndef Attack_h
#define Attack_h

#include <vector>

#include "ValueRange.h"
#include "Effect.h"
#include "Characteristics.h"
#include "AttackDamage.h"
#include "Value.h"


class Attack {
  private:
  protected:
  public:
    int attackId;
    std::vector<ValueRange> damages;
    std::vector<Effect> effects;
    int cost;
    int minRange;
    int maxRange;
    bool isInLine;
    bool needVision;
    int effectSize;

  public:
    Attack()
    {
      // @todo
    }
    // Public methods

    /**
     *  @param c TBD
     */
    Attack applyCharacteristics(const Characteristics& c) const{
        // TODO
    }

    /**
     *  @param distFromCenter TBD
     *  @return AttackDamage
     */
    AttackDamage sampleDamage(const int& distFromCenter=0) const {
        std::vector<Value> finalDamages;
        for(auto range : damages){
            finalDamages.push_back(range.sample());
        }
        return AttackDamage(attackId, finalDamages, effects);
    }

    bool operator==(const Attack& other) const {
        if(attackId != other.attackId) return false;
        if(damages.size() != other.damages.size()) return false;
        if(effects.size() != other.effects.size()) return false;
        if(cost != other.cost) return false;
        if(minRange != other.minRange) return false;
        if(maxRange != other.maxRange) return false;
        if(isInLine != other.isInLine) return false;
        if(needVision != other.needVision) return false;
        if(effectSize != other.effectSize) return false;
        // TOODO: check that damages and effect are acualy the same...
        return true;
    }


  // Protected methods
  protected:

  // Private methods
  private:
};

#endif // Attack_h
