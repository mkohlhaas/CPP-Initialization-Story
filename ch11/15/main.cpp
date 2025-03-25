#include "globals.h"
#include <iostream>

int
main()
{
    std::cout << gMyGlobal << ", " << gHelloText << '\n';                              //  10, Hello World
    std::cout << appConstants::scalingFactor << ", " << appConstants::appName << '\n'; // 1.33, Testing app
}
