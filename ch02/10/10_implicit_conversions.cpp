#include <print>
#include <string>

struct Product
{
    Product() : name{"default product"}, value{}
    {
    }

    // By default, declare single-argument constructors explicit.
    // Reason: To avoid unintended conversions!

    explicit Product(int v) : name{"basic"}, value{v}
    {
    }

    Product(const std::string &n, int v) : name{n}, value{v}
    {
    }

    std::string name;
    int         value;
};

void
printProduct(const Product &prod)
{
    std::println("{}, {}", prod.name, prod.value);
}

int
main()
{
    Product numbers = 100.1;        // copy initialization
    Product box     = {"a box", 1}; // copy list-initialization

    printProduct({"a box", 2.1});   // a box, 2

    int someRandomNumber = 100;
    printProduct(someRandomNumber); // basic, 100
}
