/**
 * \file Characteristics.h
 */

#ifndef Characteristics_h
#define Characteristics_h

#include <map>

#include "Range.h"

class CharacteristicsRange;

class Characteristics {
private:
protected:
public:
    std::map<ValueType,int> baseValue;
    std::map<ValueType,int> fixedBonuses;
    std::map<ValueType,int> relativeBonuses;
    std::map<ValueType,int> fixedArmor;
    std::map<ValueType,int> relativeArmor;

    char actionPoint;
    char movePoint;

    friend class CharacteristicsRange;
public:
    Characteristics()
    {
        // @todo
    }
    // Public methods

    /**
     *  @param baseRange TBD
     *  @return Range
     */
    Range apply(const Range& baseRange) const {
        // @todo
        return baseRange;
    }

    /**
     *  @param other TBD
     *  @return Characteristics&
     */
    Characteristics& operator+=(const Characteristics& other) {
        for(auto pair : other.baseValue){
            baseValue[pair.first] += pair.second;
        }
        for(auto pair : other.fixedBonuses){
            fixedBonuses[pair.first] += pair.second;
        }
        for(auto pair : other.relativeBonuses){
            relativeBonuses[pair.first] += pair.second;
        }
        for(auto pair : other.fixedArmor){
            fixedArmor[pair.first] += pair.second;
        }
        for(auto pair : other.relativeArmor){
            relativeArmor[pair.first] += pair.second;
        }
        movePoint += other.movePoint;
        actionPoint += other.actionPoint;
        return *this;
    }

    /**
     *  @param lhs TBD
     *  @param rhs TBD
     *  @return Characteristics
     */
    friend Characteristics operator+(Characteristics lhs, const Characteristics& rhs) {
        lhs += rhs;
        return lhs;
    }

    /**
     *  @param other TBD
     *  @return Characteristics&
     */
    bool operator==(const Characteristics& other) const{
        for(auto pair : other.baseValue){
            if(baseValue.at(pair.first) != pair.second) return false;
        }
        for(auto pair : other.fixedBonuses){
            if(fixedBonuses.at(pair.first) != pair.second) return false;
        }
        for(auto pair : other.relativeBonuses){
            if(relativeBonuses.at(pair.first) != pair.second) return false;
        }
        for(auto pair : other.fixedArmor){
            if(fixedArmor.at(pair.first) != pair.second) return false;
        }
        for(auto pair : other.relativeArmor){
            if(relativeArmor.at(pair.first) != pair.second) return false;
        }
        if(movePoint != other.movePoint || actionPoint != other.actionPoint)
            return false;
        return true;
    }


    // Protected methods
protected:

    // Private methods
private:
};

#endif // Characteristics_h
