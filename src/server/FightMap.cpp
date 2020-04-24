#include "FightMap.h"


ZoneOfControl::ZoneOfControl(const std::shared_ptr<Living> &living, const char &team):
    team(team), livingZoc(living)
{
}

const char &ZoneOfControl::getTeam() const{
    return team;
}

const std::shared_ptr<Living> &ZoneOfControl::getLiving() const{
    return livingZoc;
}







const std::vector<Point> FightMap::zocPoints = {Point(0,1), Point(1,0), Point(0,-1), Point(-1,0)};



FightMap::FightMap(const std::shared_ptr<MapTiles> &map): baseMap(map)
{
}

void FightMap::addLiving(const std::shared_ptr<Living> &living, const char &team){
    addObstacle(living->getPos());
    for(const Point& p : zocPoints){
        zoneOfControls.emplace(p + living->getPos(), ZoneOfControl(living, team));
    }
}

void FightMap::moveLiving(const Point &oldPos, const Point &newPos){
    removeObstacle(oldPos);
    addObstacle(newPos);
    for(const Point& p : zocPoints){
        bool found = false;
        // range shouldn't be bigger than 4 element, at worst
        auto range = zoneOfControls.equal_range(p + oldPos);
        for(auto it=range.first ; it != range.second ; ++it){
            const Point& livingPoint = it->second.getLiving()->getPos();
            if(livingPoint == oldPos){
                found = true;
                // move the zoc to a new position
                zoneOfControls.emplace(p + newPos, it->second);
                // remove the old position zoc
                zoneOfControls.erase(it);
                break;
            }
        }
        assert(found == true);
    }
}

void FightMap::removeLiving(const std::shared_ptr<Living> &living){
    removeObstacle(living->getPos());
    for(const Point& p : zocPoints){
        bool found = false;
        // range shouldn't be bigger than 4 element, at worst
        auto range = zoneOfControls.equal_range(p + living->getPos());
        for(auto it=range.first ; it != range.second ; ++it){
            if(living == it->second.getLiving()){
                found = true;
                // remove the old position zoc
                zoneOfControls.erase(it);
                break;
            }
        }
        assert(found == true);
    }
}

void FightMap::addObstacle(const Point &point){
    dynamicObstacle.insert(point);
}

void FightMap::removeObstacle(const Point &point){
    dynamicObstacle.erase(point);
}

void FightMap::moveObstacle(const Point &oldPoint, const Point &newPoint){
    removeObstacle(oldPoint);
    addObstacle(newPoint);
}
