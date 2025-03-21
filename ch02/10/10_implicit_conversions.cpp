#include <print>
#include <string>

struct Product
{
    Product() : name{"default product"}, value{}
    {
    }

    Product(double v) : name{"basic"}, value{v}
    {
    }

    Product(const std::string &n, double v) : name{n}, value{v}
    {
    }

    std::string name;
    double      value;
};

void
printProduct(const Product &prod)
{
    std::println("{}, {}", prod.name, prod.value);
}

int
main()
{
    int someRandomNumber = 100;
    printProduct(someRandomNumber); // basic, 100
    printProduct({"a box", 2});     // a box, 2
}
