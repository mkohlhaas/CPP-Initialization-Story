#include "value.h"
#include <iostream>

// Internal linkage

const Value v{42}; // internal linkage | Value(42)
                   //                  | Value(100)
void foo();

int
main()
{
    std::cout << "in main(): " << &v << '\n'; // in main(): 0x60cb92e6b154
    foo();                                    // in foo(): 0x60cb92e6b158
    std::cout << "main ends...\n";            // main ends...
}
// ~Value(100)
// ~Value(42)
