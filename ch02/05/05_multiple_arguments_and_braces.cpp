#include <print>
#include <string>
#include <vector>

struct Product
{
    Product() : name{"default product"}, value{}
    {
    }

    Product(char a, char b, char c, double v) : name{a, b, c}, value{v}
    {
    }

    std::string name;
    double      value;
};

int
main()
{
    std::vector<int> vec1{1, 2};                 // holds two values, 1 and 2
    std::vector<int> vec2(1, 2);                 // holds one value, 2!

    std::println("{}", vec1.size());             // 2
    std::println("{}", vec2.size());             // 1

    Product def{};
    std::println("{}, {}", def.name, def.value); // default product, 0

    Product p{'x', 'y', 'z', 100.0};
    std::println("{}, {}", p.name, p.value);     // xyz, 100
}
