#include "MapManager.h"
#include "Player.h"
#include "MonsterTeam.h"
#include "MapObject.h"


MapManager::MapManager()
{
    tiles = std::make_shared<MapTiles>(8,8);
}

void MapManager::addPlayer(std::shared_ptr<Player> &player)
{
    player->setMapManager(shared_from_this());
    players[player->getLivingId()] = player;

    connectPlayer(player);
    emit newLiving(player);
}

void MapManager::removePlayer(std::shared_ptr<Player> &player)
{
    players.erase(player->getLivingId());

    disconnectPlayer(player);
    emit livingLeaved(player->getLivingId());
}

bool MapManager::checkMovePossible(const std::vector<Point> &path)
{
    // TODO manage path cut for monster aggretion
    for(const Point& p : path){
        if(tiles->getTile(p) != TileType::Free){
            return false;
        }
    }
    return true;
}

const std::shared_ptr<MapTiles> &MapManager::getTiles() const
{
    return tiles;
}

const std::map<int, std::shared_ptr<Player> > &MapManager::getPlayers() const
{
    return players;
}

const std::map<int, std::shared_ptr<MonsterTeam> > &MapManager::getMonsters() const
{
    return monsters;
}

void MapManager::connectPlayer(std::shared_ptr<Player> &player)
{
    connect(&(*player), SIGNAL(moveRequest(const std::shared_ptr<Living>&, const std::vector<Point>&)), this, SLOT(onMoveRequest(const std::shared_ptr<Living>&, const std::vector<Point>&)));
}

void MapManager::disconnectPlayer(std::shared_ptr<Player> &player)
{
    disconnect(&(*player), SIGNAL(moveRequest(const std::shared_ptr<Living>&, const std::vector<Point>&)), this, SLOT(onMoveRequest(const std::shared_ptr<Living>&, const std::vector<Point>&)));
}

void MapManager::onMoveRequest(const std::shared_ptr<Living> &living, const std::vector<Point>& path)
{
    if(!checkMovePossible(path)){
        return;
    }
    if(living->getPos() != path[0]){
        std::cout << "Path does not start from the right location" << std::endl;
        return;
    }
    living->setMove(path);
    emit move(living->getLivingId(), path);
}
