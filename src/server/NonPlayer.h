/**
 * \file NonPlayer.h
 */

#ifndef NonPlayer_h
#define NonPlayer_h

#include <vector>

#include "Character.h"
#include "Action.h"

class NonPlayer: public Character {
    Q_OBJECT
  protected:
    std::vector<Action> possibleActions;
  public:

  public:
    NonPlayer(): Character()
    {
      // @todo
    }
};

#endif // NonPlayer_h
