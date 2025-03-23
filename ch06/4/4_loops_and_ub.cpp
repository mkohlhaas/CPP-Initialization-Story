#include <iostream>
#include <vector>

// lifetime extension: rvalue references and const lvalue references can extend lifetime of temporary objects - so the
// temporary lives till the reference lives.
// Both - rvalue references and const lvalue references - can bind to rvalue references (T&&).

auto
getVec()
{
    std::vector<std::vector<int>> ints{
        {1, 2},
        {3, 4},
        {5, 6},
    };
    return ints;
}

int
main()
{
    // outer vector's lifetime is not extended, only inner vector ({3, 4})
    for (auto &i : getVec()[1])
    {
        std::cout << i << '\n'; // inderminate values are printed
    }

    // this works
    for (auto temp = getVec(); auto &i : temp[1])
    {
        std::cout << i << '\n'; // 3 4
    }
}
