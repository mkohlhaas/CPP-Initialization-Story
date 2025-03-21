#include <print>

struct Value
{
    Value() = default;

    int x;
};

struct CtorValue
{
    CtorValue() = default;

    CtorValue(int v) : x{v}
    {
    }

    int x;
};

struct DeletedValue
{
    DeletedValue() = delete;

    DeletedValue(int v) : x{v}
    {
    }

    int x;
};

int
main()
{
    Value v1;                 // fine, default constructor available
    std::println("{}", v1.x); // (random value)

    CtorValue v2;             // ok now, default ctor available
    std::println("{}", v2.x); // (random value)

    CtorValue v3{10};         // using custom ctor
    std::println("{}", v3.x); // 10

    // DeletedValue v4;       // err, deleted ctor!

    DeletedValue v5{10};      // using custom ctor
    std::println("{}", v5.x); // 10
}
