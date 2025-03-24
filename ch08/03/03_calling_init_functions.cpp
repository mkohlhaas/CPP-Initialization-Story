#include <iostream>
#include <string>

int
initA()
{
    std::cout << "initA() called\n";
    return 1;
}

std::string
initB()
{
    std::cout << "initB() called\n";
    return "Hello";
}

struct SimpleType
{
    int         a{initA()};
    std::string b{initB()};

    SimpleType()
    {
        std::cout << "SimpleType()\n";
    }

    SimpleType(int x) : a(x)
    {
        std::cout << "SimpleType(int)\n";
    }
};

int
main()
{
    SimpleType t0;

    std::cout << std::endl;

    SimpleType t1(10);
}
