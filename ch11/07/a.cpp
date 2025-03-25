#include "point.h"
#include <iostream>

extern Point center;

Point offset = {center.x + 100, center.y + 200};

void
foo()
{
    std::cout << offset.x << ", " << offset.y << '\n';
}
