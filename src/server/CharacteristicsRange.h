/**
 * \file CharacteristicsRange.h
 */

#ifndef CharacteristicsRange_h
#define CharacteristicsRange_h

#include <map>

#include "Range.h"
#include "Characteristics.h"


class CharacteristicsRange {
public:
    std::map<ValueType,Range> baseValue;
    std::map<ValueType,Range> fixedBonuses;
    std::map<ValueType,Range> relativeBonuses;
    std::map<ValueType,Range> fixedArmor;
    std::map<ValueType,Range> relativeArmor;

public:
    CharacteristicsRange()
    {
        // @todo
    }
    // Public methods

    /**
     *  @return Characteristics
     */
    Characteristics sample() const{
        Characteristics c;
        for(auto pair : baseValue){
            c.baseValue[pair.first] = pair.second.sample();
        }
        for(auto pair : fixedBonuses){
            c.fixedBonuses[pair.first] = pair.second.sample();
        }
        for(auto pair : relativeBonuses){
            c.relativeBonuses[pair.first] = pair.second.sample();
        }
        for(auto pair : fixedArmor){
            c.fixedArmor[pair.first] = pair.second.sample();
        }
        for(auto pair : relativeArmor){
            c.relativeArmor[pair.first] = pair.second.sample();
        }
        return c;
    }


    // Protected methods
protected:

    // Private methods
private:
};

#endif // CharacteristicsRange_h
