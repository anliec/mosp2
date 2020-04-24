/**
 * \file World.h
 */

#ifndef World_h
#define World_h

#include <memory>

#include "MapManager.h"

typedef long WorldTime; // server time type, 1/10 of a second increment
static const WorldTime SERVER_TICK_PER_SECOND = 10;


class World {
private:
    std::map<int,std::shared_ptr<MapManager>> maps;

    static std::chrono::system_clock::time_point startTime;
//    static std::shared_ptr<World> world;

private:
    World();
    ~World();
    // Public methods
public:
    // delete default function to ensure singleton
    World(World const&) = delete;
    void operator=(World const&) = delete;
    /**
     *  @return shared_ptr<World>
     */
    static World* makeWorld();

    /**
     *  @param x TBD
     *  @param y TBD
     *  @return shared_ptr<mapManager>
     */
    std::shared_ptr<MapManager> getMap(const int& mapId);

    static WorldTime getCurrentTime();
};

#endif // World_h
