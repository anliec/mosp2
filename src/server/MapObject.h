/**
 * \file MapObject.h
 */

#ifndef MapObject_h
#define MapObject_h

#include <QObject>
#include <memory>

#include "Pos.h"

class MapObject : public QObject {
    Q_OBJECT
  protected:
    Pos pos;

  public:
    MapObject(const Pos& ObjectPosition = Pos()): pos(ObjectPosition)
    {
    }

    virtual ~MapObject()
    {
    }
    // Public methods

    virtual Pos getPos() const{
        return pos;
    }


  public slots:
    /**
     *  @param pos TBD
     */
    void setPos(const Pos& newPos) {
        emit posChanged(pos, newPos);
        pos = newPos;
    }


  signals:
    void posChanged(const Pos& oldPos, const Pos& newPos);
};

#endif // MapObject_h
