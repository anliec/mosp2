/**
 * \file Player.h
 */

#ifndef Player_h
#define Player_h

#include <vector>
#include <memory>

#include "Character.h"
#include "BagObject.h"
#include "FightEndResult.h"


class Player: public Character {
    Q_OBJECT
  protected:
    std::vector<std::shared_ptr<BagObject>> bag;

  public:
    Player(): Character()
    {
      // @todo
    }
    // Public methods

    /**
     *  @return int
     */
    int getBagWeight() {
      // @todo 
    }

    /**
     *  @return Characteristics
     */
    Characteristics getTotalCurrentCharacteristics() {
      // @todo 
    }

//    virtual void getEndOfFightResult(const FightEndResult& result) = 0;
//    virtual void sendFullMap() = 0;
//    virtual void sendLivingMove(const int& livingId, const std::vector<Point>& path) = 0;
//    virtual void sendNewMapObject(const std::shared_ptr<MapObject>& object) = 0;
//    virtual void sendAttack(const std::shared_ptr<Living>& living, const AttackDamage& attack) = 0;
//    virtual void onMoveRequest(const std::vector<Point>& path) = 0;
//    virtual void onAttackRequest(const int& attackId) = 0;


  // Protected methods
  protected:

  // Private methods
  private:
};

#endif // Player_h
