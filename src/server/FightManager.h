/**
 * \file FightManager.h
 */

#ifndef FightManager_h
#define FightManager_h

#include <QObject>
#include <vector>
#include <list>
#include <memory>

#include "MapTiles.h"
#include "FightEndResult.h"
#include "World.h"

class Player;
class MonsterTeam;
class MapObject;
class MapManager;
class Living;
class InteractiveObject;

class FightManager {
private:
    std::vector<std::shared_ptr<Living>> team1;
    std::vector<std::shared_ptr<Living>> team2;
    std::vector<std::shared_ptr<InteractiveObject>> staticObjects;
    std::shared_ptr<MapTiles> tiles;
    std::shared_ptr<MapManager> parentMapManager;
    int turnNumber;
    std::list<std::shared_ptr<Living>> playingOrder;
    std::list<std::shared_ptr<Living>>::iterator currentPlayer;
    bool isStartPhase;
    WorldTime currentPlayerStartTime;

public:
    FightManager(std::vector<std::shared_ptr<Living>>& team1, std::vector<std::shared_ptr<Living>>& team2):
        team1(team1), team2(team2), isStartPhase(true)
    {
    }

private:
    /**
     *  @param player TBD
     *  @return FightEndResult
     */
    FightEndResult getEndResultForPlayer(const std::shared_ptr<Player>& player) {
        // @todo
    }

};

#endif // FightManager_h
