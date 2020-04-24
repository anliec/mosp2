/**
 * \file Living.h
 */

#ifndef Living_h
#define Living_h

#include <vector>
#include <memory>
#include <string>

#include "MapObject.h"
#include "Characteristics.h"
#include "AttackDamage.h"
#include "Move.h"
#include "MapManager.h"
#include "FightManager.h"
#include "ActiveEffect.h"
#include "Attack.h"
#include "World.h"

static const double WALK_SPEED_FACTOR = 0.1 / SERVER_TICK_PER_SECOND;


class Living: public MapObject, public std::enable_shared_from_this<Living> {
    Q_OBJECT

  private:
    Characteristics tmpTotalCharac;
  protected:
    int level;
    std::string name;
    Characteristics baseCharac;
    std::vector<ActiveEffect> effects;
    std::vector<Attack> attacks;
    std::shared_ptr<FightManager> fightManager;
    std::shared_ptr<MapManager> mapManager;
    std::shared_ptr<Move> currentMove;
    int livingId;
    int livePoint;

  public:
    Living();
    virtual ~Living();

  public slots:
    AttackDamage getDamage(AttackDamage damage);
    Characteristics getTotalCurrentCharacteristics() const;
    virtual void updateTotalCurrentCharacteristics();
    bool isInState(const State& state);
    void RequestMove(const std::vector<Point>& path);

    /**
     * @brief setMove set the current move, initialise times and speed, do not check move validity
     * @param path path to follow
     */
    void setMove(std::vector<Point> path);
    void onMoveDone();
    void RequestAttack(const int& attackId, const Pos& pos);
    virtual Pos getPos() const;
    std::string getName() const;
    const int& getLevel() const;
    const int& getLivingId() const;
    const int& getLivePoint() const;

    void setMapManager(std::shared_ptr<MapManager> newMapManager);
    std::shared_ptr<MapManager> getMapManager();


  signals:
    void moveRequest(const std::shared_ptr<Living>& living, const std::vector<Point>& path);
    void newMove();
    void mapChanged(std::shared_ptr<MapManager> manager);
};

#endif // Living_h
