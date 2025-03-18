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
    Value v;                 // fine, default constructor available
    std::println("{}", v.x);

    CtorValue y;             // ok now, default ctor available
    std::println("{}", y.x); //

    CtorValue z{10};         // using custom ctor
    // DeletedValue w;       // err, deleted ctor!
    DeletedValue u{10}; // using custom ctor
}
