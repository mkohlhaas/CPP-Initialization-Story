#include <iostream>
#include <string>

struct Box
{
};

struct Product
{
    Product() : name{"default product"}
    {
    }

    Product(const Box &) : name{"box"}
    {
    }

    std::string name;
};

int
main()
{
    // Product p();          // compiler sees this as a function declaration!
    // std::cout << p.name;  // error

    // Product p2(Box());    // compiler sees this as a function declaration!
    // std::cout << p2.name; // error

    Product p2((Box()));
    std::cout << p2.name; // box
}
