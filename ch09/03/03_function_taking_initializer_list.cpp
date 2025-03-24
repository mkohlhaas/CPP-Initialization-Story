#include <initializer_list>
#include <iostream>

// std::initializer_list looks like a regular container.
// You can use std::empty(), for-range-loops, .size(), ...

// std::initializer_list is a "view" type; it references some implementation-
// dependent and a local array of const values. Use it mainly for passing into
// functions. Do not return such lists from functions.

void
foo(std::initializer_list<int> list) // no need to use const, const &, ..., (just by value)
{

    if (std::empty(list))
    {
        std::cout << "empty list\n";
    }
    else
    {
        for (auto &x : list)
        {
            std::cout << x << ", ";
        }
        std::cout << "(" << list.size() << " elements)\n";
    }
}

int
main()
{
    foo({});              // empty list
    foo({1, 2, 3});       // 1, 2, 3, (3 elements)
    foo({1, 2, 3, 4, 5}); // 1, 2, 3, 4, 5, (5 elements)
}
