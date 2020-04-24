/**
 * \file MapManager.h
 */

#ifndef MapManager_h
#define MapManager_h

#include <list>
#include <vector>
#include <map>
#include <memory>

#include <QObject>

#include "MapTiles.h"
#include "StartPos.h"

class Player;
class MonsterTeam;
class MapObject;
class FightManager;
class Living;

class MapManager: public QObject, public std::enable_shared_from_this<MapManager> {
    Q_OBJECT
private:
    std::list<std::shared_ptr<MapObject>> objects;
    std::map<int,std::shared_ptr<Player>> players;
    std::map<int,std::shared_ptr<MonsterTeam>> monsters;
    std::shared_ptr<MapTiles> tiles;
    std::vector<StartPos> fightStartPoses;
    std::list<std::shared_ptr<FightManager>> onGoingFight;

public:
    MapManager();

public slots:
    void addPlayer(std::shared_ptr<Player>& player);
    void removePlayer(std::shared_ptr<Player>& player);

    bool checkMovePossible(const std::vector<Point>& path);

    const std::shared_ptr<MapTiles>& getTiles() const;
    const std::map<int,std::shared_ptr<Player>>& getPlayers() const;
    const std::map<int,std::shared_ptr<MonsterTeam>>& getMonsters() const;

protected slots:
    void connectPlayer(std::shared_ptr<Player>& player);
    void disconnectPlayer(std::shared_ptr<Player>& player);
    void onMoveRequest(const std::shared_ptr<Living> &living, const std::vector<Point> &path);

signals:
    void move(const int& livingId, const std::vector<Point> &path);
    void newLiving(std::shared_ptr<Living> living);
    void livingLeaved(const int& livingId);
};

#endif // MapManager_h
