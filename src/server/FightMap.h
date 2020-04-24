#ifndef FIGHTMAP_H
#define FIGHTMAP_H

#include <memory>
#include <unordered_map>
#include <unordered_set>

#include "MapTiles.h"
#include "Point.h"
#include "Living.h"

//class Living;

class ZoneOfControl{
private:
    const char team;
    const std::shared_ptr<Living> livingZoc;

public:
    ZoneOfControl(const std::shared_ptr<Living>& living, const char& team);

    const char& getTeam() const;
    const std::shared_ptr<Living>& getLiving() const;
};


class FightMap{
private:
    const std::shared_ptr<MapTiles> baseMap;
    std::unordered_set<Point> dynamicObstacle;
    std::unordered_multimap<Point,ZoneOfControl> zoneOfControls;
    static const std::vector<Point> zocPoints;

public:
    FightMap(const std::shared_ptr<MapTiles>& map);

    void addLiving(const std::shared_ptr<Living>& living, const char& team);
    void moveLiving(const Point& oldPos, const Point& newPos);
    void removeLiving(const std::shared_ptr<Living>& living);
    void addObstacle(const Point& point);
    void removeObstacle(const Point& point);
    void moveObstacle(const Point& oldPoint, const Point& newPoint);

};

#endif // FIGHTMAP_H


















