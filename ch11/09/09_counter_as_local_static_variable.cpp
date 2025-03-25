#include <iostream>

int
foo()
{
    static int counter = 0;
    return ++counter;
}

int
main()
{
    std::cout << foo() << '\n'; // 1
    std::cout << foo() << '\n'; // 2
    std::cout << foo() << '\n'; // 3

    auto finalCounter = foo();
    std::cout << finalCounter;  // 4
}
