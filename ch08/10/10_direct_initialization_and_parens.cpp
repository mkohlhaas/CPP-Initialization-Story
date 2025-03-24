#include <iostream>
#include <vector>

// The case with direct initialization and parens

class DataPacket1
{
    // std::string data_(40, '*');      // most vexing parse (syntax error, looks like a function declaration)
    // std::vector ints{1, 2, 3, 4, 5}; // CTAD (class template argument deduction) not possible!
};

// you can use copy initialization:
class DataPacket2
{
    std::string data_ = std::string(40, '*');

    std::vector<int> ints{1, 2, 3, 4, 5};
};

int
main()
{
    // bc of a constructor with the std::initializer_list in std::string, which takes precedence,
    // you need to use direct initialization with parens to call the correct version:
    std::string stars(40, '*');     // 40 stars
    std::string moreStars{40, '*'}; // 2 chars

    std::cout << stars << '\n';     // ****************************************
    std::cout << moreStars << '\n'; // (*
}
