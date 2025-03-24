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
    return "World";
}

struct SimpleType
{
    int         a{initA()};
    std::string b{initB()};

    SimpleType()
    {
    }

    explicit SimpleType(std::string s) : b(std::move(s))
    {
    }

    // [1]
    // copy constructor
    // SimpleType(const SimpleType &other)
    // {
    //     a = other.a;
    //     b = other.b;
    //     std::cout << "copy ctor\n";
    // };

    // [2]
    // copy constructor
    SimpleType(const SimpleType &other) : a{other.a}, b{other.b}
    {
        std::cout << "copy ctor\n";
    };

    // [3]
    // copy constructor
    // SimpleType(const SimpleType &other) = default;
};

int
main()
{
    SimpleType t1;
    std::cout << std::endl;
    SimpleType t2 = t1;
}
