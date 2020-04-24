/**
 * \file Pos.h
 */

#ifndef Pos_h
#define Pos_h

#include "Point.h"

enum class Angle {TopLeft, Top, TopRight, Right, BottomRight, Bottom, BottomLeft, Left, None};

template <class T>
class BasePos: public BasePoint<T> {
  private:
  protected:
  public:
    Angle angle;

  public:
    BasePos(const T& x=0, const T& y=0, const Angle& a=Angle::None):
        BasePoint<T>(x,y), angle(a)
    {}

    template<class O>
    BasePos(const T& x, const T& y, const BasePoint<O> direction):
        BasePoint<T>(x,y), angle(computeAngle(direction))
    {}

    BasePos(const BasePoint<T>& other, const Angle& a=Angle::None):
        BasePoint<T>(other), angle(a)
    {}

    template<class O>
    BasePos(const BasePoint<T>& other, const BasePoint<O> direction):
        BasePoint<T>(other), angle(computeAngle(direction))
    {}

    template<class O>
    BasePos(const BasePos<O>& other):
        BasePoint<T>(other.x, other.y), angle(other.angle)
    {}
    // Public methods

    template<class O>
    static Angle computeAngle(const BasePoint<O>& direction)
    {
        if(direction.x < O(0)){
            if(direction.y < O(0)){
                return Angle::TopLeft;
            }else if(direction.y == O(0)){
                return Angle::Left;
            }else{
                return Angle::BottomLeft;
            }
        }else if(direction.x == O(0)){
            if(direction.y < O(0)){
                return Angle::Top;
            }else if(direction.y == O(0)){
                return Angle::None;
            }else{
                return Angle::Bottom;
            }
        }else{
            if(direction.y < O(0)){
                return Angle::TopRight;
            }else if(direction.y == O(0)){
                return Angle::Right;
            }else{
                return Angle::BottomRight;
            }
        }
    }

    BasePos<char> round() const{
       return BasePos<char>(BasePoint<T>::round(), angle);
    }

    /**
     *  @param other TBD
     *  @return bool
     */
    bool operator==(const BasePos<T>& other) {
      return BasePoint<T>::operator==(other) && other.angle == angle;
    }

    BasePos<T>& operator+=(const BasePos<T> & other){
        BasePoint<T>::operator+=(other);
        return *this;
    }

    friend BasePos<T> operator+(BasePos<T> lhs, const BasePos<T>& rhs) {
      lhs += rhs;
      return lhs;
    }

    friend BasePoint<T> operator+(BasePoint<T> lhs, const BasePos<T>& rhs) {
      lhs.x += rhs.x;
      lhs.y += rhs.y;
      return lhs;
    }

    friend BasePoint<T> operator+(BasePos<T> lhs, const BasePoint<T>& rhs) {
      rhs.x += lhs.x;
      rhs.y += lhs.y;
      return rhs;
    }


  // Protected methods
  protected:

  // Private methods
  private:
};

typedef BasePos<char> Pos;
typedef BasePos<float> FloatPos;

#endif // Pos_h
