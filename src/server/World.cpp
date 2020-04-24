#include "World.h"
#include <chrono>
#include <iostream>

//std::shared_ptr<World> World::world = nullptr;
std::chrono::system_clock::time_point World::startTime = std::chrono::system_clock::time_point();

World::World()
{
    World::startTime = std::chrono::system_clock::now();
    maps[0] = std::make_shared<MapManager>();
}

World::~World()
{
}

World* World::makeWorld() {
    static World world;
//    static std::chrono::system_clock::time_point World::startTime;
    return &world;
}

std::shared_ptr<MapManager> World::getMap(const int &mapId) {
    try {
        return maps.at(mapId);
    } catch (std::out_of_range e) {
        std::cerr << "World: Unable to access map with ID: " << mapId << std::endl;
        return nullptr;
    }
}

WorldTime World::getCurrentTime(){
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(now - startTime).count() / (1000 / SERVER_TICK_PER_SECOND);
}
