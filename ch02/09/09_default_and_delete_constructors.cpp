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
    std::println("{}", v1.x); // (indeterminate value)

    Value v2{};               // fine, default constructor available
    std::println("{}", v2.x); // 0

    CtorValue v3;             // ok now, default ctor available
    std::println("{}", v3.x); // (indeterminate value)

    CtorValue v4{10};         // using custom ctor
    std::println("{}", v4.x); // 10

    // DeletedValue v5;       // err, deleted ctor!

    DeletedValue v6{10};      // using custom ctor
    std::println("{}", v6.x); // 10
}
