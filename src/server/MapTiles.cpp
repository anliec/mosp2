#include "MapTiles.h"

MapTiles::MapTiles(const unsigned &width, const unsigned &height): width(width), height(height){
    tiles.resize(width * height);
    for (unsigned i=0 ; i<width*height ; ++i){
        tiles[i] = TileType::Free;
    }
}

MapTiles::~MapTiles(){
}

TileType MapTiles::getTile(const unsigned &x, const unsigned &y) const {
    if(x >= width || y >= height){
        return TileType::None;
    }
    else{
        return tiles[y * width + x];
    }
}

TileType MapTiles::getTile(const Point &p) const {
    return getTile(unsigned(p.x), unsigned(p.y));
}

const unsigned &MapTiles::getWidth() const
{
    return width;
}

const unsigned &MapTiles::getHeight() const
{
    return height;
}
