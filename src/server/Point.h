/**
 * \file Point.h
 */

#ifndef Point_h
#define Point_h

#include <cmath>
#include <functional>
#include <iostream>

template <class T>
class BasePoint {
private:
protected:
public:
    T x;
    T y;

public:
    BasePoint(const T& x=0, const T& y=0):
        x(x), y(y)
    {
    }

    template<class O>
    BasePoint(const BasePoint<O>& other):
        BasePoint(other.x, other.y)
    {
    }

    // Public methods

    BasePoint<char> round() const{
        return BasePoint<char>(char(std::round(x)), char(std::round(y)));
    }

    BasePoint<T>& operator+=(const BasePoint<T>& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    BasePoint<T>& operator-=(const BasePoint<T>& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    BasePoint<T>& operator*=(const T& val) {
        x *= val;
        y *= val;
        return *this;
    }

    friend BasePoint<T> operator+(BasePoint<T> lhs, const BasePoint<T>& rhs) {
        lhs += rhs;
        return lhs;
    }

    friend BasePoint<T> operator-(BasePoint<T> lhs, const BasePoint<T>& rhs) {
        lhs -= rhs;
        return lhs;
    }

    friend BasePoint<T> operator*(BasePoint<T> lhs, const T& rhs) {
        lhs *= rhs;
        return lhs;
    }

    friend BasePoint<T> operator*(const T& lhs, BasePoint<T> rhs) {
        rhs *= lhs;
        return rhs;
    }

    /**
     *  @param other TBD
     *  @return bool
     */
    bool operator==(const BasePoint<T>& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const BasePoint<T>& other) const {
        return x != other.x || y != other.y;
    }

    // Protected methods
protected:

    // Private methods
private:
};



template<class T>
std::ostream &operator<<(std::ostream &os, BasePoint<T> const & other);
//template<>
//std::ostream &operator<<(std::ostream &os, BasePoint<char> const & other);


typedef BasePoint<char> Point;
typedef BasePoint<float> FloatPoint;






namespace std {
template <class T>
struct hash<BasePoint<T>>
{
    std::size_t operator()(const BasePoint<T>& p) const
    {
        return std::size_t(char(p.x)) + std::size_t(char(p.y)) * 256;
    }
};

template<class T>
struct less<BasePoint<T>>
{
    bool operator() (const BasePoint<T>& lhs, const BasePoint<T>& rhs) const
    {
        return (lhs.x + lhs.y * 256) < (rhs.x + rhs.y * 256);
    }
};

}




#endif // Point_h
