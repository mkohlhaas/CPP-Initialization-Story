#include "value.h"
#include <iostream>

// Static duration and external linkage

Value v{42}; // Value(42)

void foo();
int
main()
{
    std::cout << "in main(): " << &v << '\n'; // in main(): 0x5b8b1733f154
    foo();                                    // in foo(): 0x5b8b1733f154
    std::cout << "main ends...\n";            // main ends...
}
// ~Value(42)
