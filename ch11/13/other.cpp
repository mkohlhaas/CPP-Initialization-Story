#include "test.h"

static Value local{200};

void
foo()
{
    std::cout << "foo starting...\n";
    Test t;
    std::cout << local.v << '\n';
}
