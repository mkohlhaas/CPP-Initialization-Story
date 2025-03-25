#include <iostream>
#include <utility>

constinit std::pair<int, double> global{42, 42.2}; // can be changed later
constexpr std::pair<int, double> constG{42, 42.2}; // this is constant

int
main()
{
    std::cout << global.first << ", " << global.second << '\n'; // 42, 42.2
    global = {10, 10.1};
    std::cout << global.first << ", " << global.second << '\n'; // 10, 10.1

    std::cout << constG.first << ", " << constG.second << '\n'; // 42, 42.2
    // constG = { 10, 10.1 };                                   // not allowed, const
}
