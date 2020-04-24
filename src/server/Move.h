/**
 * \file Move.h
 */

#ifndef Move_h
#define Move_h

#include <QObject>

#include <vector>
#include <cmath>
#include <assert.h>

#include "Pos.h"
#include "World.h"


class Move: public QObject {
    Q_OBJECT
  private:
    std::vector<Point> path;
    WorldTime startTime;
    WorldTime endTime;
    double speed;

  public:
    Move(const WorldTime& startTime, const double& speed, std::vector<Point> path);
    // Public methods

public slots:
    /**
     *  @param time TBD
     *  @return FloatPos
     */
    FloatPos getPos(const WorldTime& time) const;
    FloatPos getFinalPos() const;

    bool isDone(const WorldTime& currentTime) const;

    // when serializing, save time how long ago was the start, not the current time.

signals:
    void moveDone() const;

};

#endif // Move_h
