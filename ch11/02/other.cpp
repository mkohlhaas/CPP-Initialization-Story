#include "value.h"
#include <iostream>

extern Value v; // declaration only!

void
foo()
{
    std::cout << "in foo(): " << &v << '\n';
}
