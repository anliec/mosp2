/**
 * \file Effect.h
 */

#ifndef Effect_h
#define Effect_h

#include <vector>

#include "ValueRange.h"
#include "Characteristics.h"

enum class State {Sleep, Curred};


class Effect {
  private:
  protected:
  public:
    Characteristics modifier;
    std::vector<ValueRange> damages;
    std::vector<State> states;
    int duration;

  public:
    Effect()
    {
      // @todo
    }
    // Public methods


  // Protected methods
  protected:

  // Private methods
  private:
};

#endif // Effect_h
