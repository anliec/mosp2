/**
 * \file Range.h
 */

#ifndef Range_h
#define Range_h

#include <stdlib.h>

#include "Value.h"

class Range {
  private:
  protected:
    int min;
    int range;
  public:

  public:
    Range(const int& minValue, const int& maxValue): min(minValue), range(maxValue + 1 - minValue)
    {
    }
    // Public methods

    /**
     *  @brief Sample an int in the curent range (expect rand to be properly initialized)
     *  @return int randomly sampled in the range
     */
    int sample() const{
      return min + (rand() % range);
    }

    int getMin() const{
        return min;
    }

    int getMax() const{
        return min + range - 1;
    }

    int getRange() const{
        return range;
    }

protected:

    // Private methods
private:
};

#endif // Range_h
