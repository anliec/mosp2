#ifndef VALUERANGE_H
#define VALUERANGE_H

#include <stdlib.h>

#include "Range.h"
#include "Value.h"

class ValueRange : public Range {
  private:
  protected:
    ValueType type;
  public:

  public:
    ValueRange(const int& minValue, const int& maxValue, const ValueType& type): Range(minValue, maxValue), type(type)
    {
    }
    // Public methods

    /**
     *  @brief Sample a value in the curent range (expect rand to be properly initialized)
     *  @return Value randomly sampled in the range
     */
    Value sample() const{
      return Value(Range::sample(), type);
    }

    ValueType getType() const{
        return type;
    }

protected:

    // Private methods
private:
};


#endif // VALUERANGE_H
