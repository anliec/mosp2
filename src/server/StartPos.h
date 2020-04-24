/**
 * \file startPos.h
 */

#ifndef startPos_h
#define startPos_h

#include <vector>

#include "Point.h"

class StartPos {
  public:
    std::vector<Point> team1;
    std::vector<Point> team2;

  public:
    StartPos();
};

#endif // startPos_h
