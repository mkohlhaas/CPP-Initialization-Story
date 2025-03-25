#include "value.h"

static Value v{100}; // internal linkage

void
foo()
{
    std::cout << "in foo(): " << &v << '\n';
}
