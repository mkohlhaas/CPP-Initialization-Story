#include <print>

struct Value
{
    int x;
};

struct CtorValue
{
    CtorValue(int v) : x{v}
    {
    }

    int x;
};

int
main()
{
    Value v1;                 // fine, default constructor available
    std::println("{}", v1.x); // (random value)

    Value v2{};               // fine, default constructor available
    std::println("{}", v2.x); // 0

    // CtorValue y;          // error! no default ctor available
    CtorValue z{10};         // using custom ctor
    std::println("{}", z.x); // 10
}
