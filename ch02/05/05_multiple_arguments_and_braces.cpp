#include <print>
#include <string>

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
    Product def{};
    std::println("{}, {}", def.name, def.value); // default product, 0

    Product p{'x', 'y', 'z', 100.0};
    std::println("{}, {}", p.name, p.value);     // xyz, 100
}
