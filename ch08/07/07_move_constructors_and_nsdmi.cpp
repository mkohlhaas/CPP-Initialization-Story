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

    SimpleType(const SimpleType &other) = default;

    // [1]
    // SimpleType(SimpleType &&other)
    // {
    //     std::cout << "move ctor\n";
    //
    //     a = std::move(other.a);
    //     b = std::move(other.b);
    // };

    // [2]
    SimpleType(SimpleType &&other) noexcept : a{std::move(other.a)}, b{std::move(other.b)}
    {
        std::cout << "move ctor\n";
    };
};

int
main()
{
    SimpleType t1;

    std::cout << std::endl;

    SimpleType t2{"Hi"};

    std::cout << std::endl;

    SimpleType t3 = std::move(t1);
}
