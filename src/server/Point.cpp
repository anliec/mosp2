#include "Point.h"

template<class T>
std::ostream &operator<<(std::ostream &os, BasePoint<T> const & other) {
    return os << "(" << other.x << "," << other.y << ")";
}

template<>
std::ostream &operator<<(std::ostream &os, BasePoint<char> const & other) {
    return os << "(" << int(other.x) << "," << int(other.y) << ")";
}

