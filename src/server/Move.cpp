#include "Move.h"

Move::Move(const WorldTime &startTime, const double &speed, std::vector<Point> path):
    path(path), startTime(startTime), speed(speed)
{
    assert(path.size() > 0);
    assert(speed > 0.0);
    endTime = startTime + WorldTime(double(path.size() - 1) / speed);
}

FloatPos Move::getPos(const WorldTime &time) const {
    FloatPoint point;
    if(isDone(time)){
        return getFinalPos();
    }
    else {
        double index = double(time - startTime) * speed;
        unsigned long prevIndex(std::floor(index));
        unsigned long nextIndex(std::ceil(index));
        FloatPoint prev(path[prevIndex]), next(path[nextIndex]);
        FloatPoint move = next - prev;
        float ratio = float(index) - float(prevIndex);
        point = prev + (move * ratio);
        return FloatPos(point, move);
    }
}

FloatPos Move::getFinalPos() const
{
    FloatPoint point = path.back();
    if(path.size() > 1){
        FloatPoint move = path.back() - path.at(path.size() - 2);
        return FloatPos(point, move);
    }
    else{
        return FloatPos(point);
    }
}

bool Move::isDone(const WorldTime &currentTime) const{
    bool done = currentTime >= endTime;
    if(done) emit moveDone();
    return done;
}
