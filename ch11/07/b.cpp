#include "point.h"

Point
createPoint(double x, double y)
{
    return Point{x, y};
}

Point center = createPoint(100, 200); // dynamic
