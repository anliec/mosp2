/**
 * \file MapTiles.h
 */

#ifndef MapTiles_h
#define MapTiles_h

#include <vector>

#include "Point.h"

enum class TileType {Free, Ocupied, Obstacle, None};


class MapTiles {
  protected:
    std::vector<TileType> tiles;
    unsigned width;
    unsigned height;

  public:
    MapTiles(const unsigned &width, const unsigned &height);

    ~MapTiles();

    TileType getTile(const unsigned& x, const unsigned& y) const;
    TileType getTile(const Point& p) const;

    const unsigned& getWidth() const;
    const unsigned& getHeight() const;
};

#endif // MapTiles_h
