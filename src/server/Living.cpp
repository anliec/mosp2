#include "Living.h"

Living::Living(): MapObject()
{
    static int lastId = 1;
    livingId = lastId++;
    name = "DefaultLiving";
    livePoint = 10;
    baseCharac.movePoint = 3;
    baseCharac.actionPoint = 6;
    tmpTotalCharac = baseCharac;
    currentMove = nullptr;
}

Living::~Living(){

}

AttackDamage Living::getDamage(AttackDamage damage) {
    // @todo
}

Characteristics Living::getTotalCurrentCharacteristics() const {
    return tmpTotalCharac;
}

void Living::updateTotalCurrentCharacteristics() {
    tmpTotalCharac = baseCharac;
    for(const ActiveEffect& e : effects){
        tmpTotalCharac += e.modifier;
    }
}

bool Living::isInState(const State &state) {
    for(const ActiveEffect& e : effects){
        for(const auto& s : e.states){
            if(state == s) return true;
        }
    }
    return false;
}

void Living::RequestMove(const std::vector<Point> &path) {
    emit moveRequest(shared_from_this(), path);
}

void Living::setMove(std::vector<Point> path){
    WorldTime now = World::getCurrentTime();
    double speed = WALK_SPEED_FACTOR * getTotalCurrentCharacteristics().movePoint;
    std::cout << "Move Path: ";
    for(auto p : path) std::cout << p << ", ";
    std::cout << std::endl;
    currentMove = std::make_shared<Move>(now, speed, path);
    QObject::connect(&(*currentMove), SIGNAL(moveDone()), this, SLOT(onMoveDone()));
    emit newMove();
}

void Living::onMoveDone(){
    QObject::disconnect(&(*currentMove), SIGNAL(moveDone()), this, SLOT(onMoveDone()));
    setPos(currentMove->getFinalPos());
    currentMove = nullptr;
}

void Living::RequestAttack(const int &attackId, const Pos &pos) {
    // @todo
}

Pos Living::getPos() const{
    if(currentMove != nullptr){
        std::shared_ptr<Move> move = currentMove;
        const WorldTime& t = World::getCurrentTime();
        const FloatPoint &p = move->getPos(t);
        const Point &p2 = p.round();
        std::cout << "Pos: " << p.x << "," << p.y << " " << p2 << std::endl;
        return p2;
    }
    else{
        return pos;
    }
}

std::string Living::getName() const {
    return name;
}

const int &Living::getLevel() const {
    return level;
}

const int &Living::getLivingId() const
{
    return livingId;
}

const int &Living::getLivePoint() const
{
    return livePoint;
}

void Living::setMapManager(std::shared_ptr<MapManager> newMapManager)
{
    if(newMapManager != mapManager){
        mapManager = newMapManager;
        emit mapChanged(mapManager);
    }
}

std::shared_ptr<MapManager> Living::getMapManager()
{
    return mapManager;
}
