#include <array>
#include <iostream>
#include <map>
#include <string>
#include <vector>

struct S
{
    int numbers[4]{1, 2, 3, 4};
    // int nums[] { 0, 1, 2 }; // need to provide the size!
    std::array<double, 3>      doubles{0.1, 1.1, 2.1};
    std::vector<int>           ints{100, 101, 102};
    std::vector<int>           moreInts = std::vector<int>(10, 1);               // we need to use copy initialization
    std::vector<std::string>   names    = std::vector<std::string>(10, "hello"); // same here (vexing parse)
    std::map<std::string, int> mapping{{"one", 1}, {"two", 2}};
};

int
main()
{
    S s;
    std::cout << "s.numbers[0]: " << s.numbers[0] << '\n';
    std::cout << "s.numbers[1]: " << s.numbers[1] << '\n';
    std::cout << "s.numbers[2]: " << s.numbers[2] << '\n';
    std::cout << "s.numbers[3]: " << s.numbers[3] << '\n';
    std::cout << std::endl;
    std::cout << "s.double[0]: " << s.doubles[0] << '\n';
    std::cout << "s.double[1]: " << s.doubles[1] << '\n';
    std::cout << "s.double[2]: " << s.doubles[2] << '\n';
    std::cout << std::endl;
    std::cout << "s.ints[0]: " << s.ints[0] << '\n';
    std::cout << "s.ints[1]: " << s.ints[1] << '\n';
    std::cout << "s.ints[2]: " << s.ints[2] << '\n';
    std::cout << std::endl;
    std::cout << "s.moreInts[0]: " << s.moreInts[0] << '\n';
    std::cout << "s.moreInts[1]: " << s.moreInts[1] << '\n';
    std::cout << "s.moreInts[2]: " << s.moreInts[2] << '\n';
    std::cout << "s.moreInts[3]: " << s.moreInts[3] << '\n';
    std::cout << "s.moreInts[4]: " << s.moreInts[4] << '\n';
    std::cout << "s.moreInts[5]: " << s.moreInts[5] << '\n';
    std::cout << "s.moreInts[6]: " << s.moreInts[6] << '\n';
    std::cout << "s.moreInts[7]: " << s.moreInts[7] << '\n';
    std::cout << "s.moreInts[8]: " << s.moreInts[8] << '\n';
    std::cout << "s.moreInts[9]: " << s.moreInts[9] << '\n';
    std::cout << std::endl;
    std::cout << "s.names[0]: " << s.names[0] << '\n';
    std::cout << "s.names[1]: " << s.names[1] << '\n';
    std::cout << "s.names[2]: " << s.names[2] << '\n';
    std::cout << "s.names[3]: " << s.names[3] << '\n';
    std::cout << "s.names[4]: " << s.names[4] << '\n';
    std::cout << "s.names[5]: " << s.names[5] << '\n';
    std::cout << "s.names[6]: " << s.names[6] << '\n';
    std::cout << "s.names[7]: " << s.names[7] << '\n';
    std::cout << "s.names[8]: " << s.names[8] << '\n';
    std::cout << "s.names[9]: " << s.names[9] << '\n';
    std::cout << std::endl;
    std::cout << "s.mapping[\"one\"]: " << s.mapping["one"] << '\n';
    std::cout << "s.mapping[\"two\"]: " << s.mapping["two"] << '\n';
}
