#include <iostream>

struct Value
{
    Value(int x) : v(x)
    {
        std::cout << "Value(" << v << ")\n";
    }

    ~Value() noexcept
    {
        std::cout << "~Value(" << v << ")\n";
    }

    int v{0};
};

struct Test
{
    Test()
    {
        puts("Test::Test()");
    }

    ~Test() noexcept
    {
        puts("Test::~Test()");
    }

    static Value  u;
    static Value  v;
    static int    w;
    static double z;
};

Value  Test::v{42}; // Value(42)
Value  Test::u{24}; // Value(24)
int    Test::w;
double Test::z = 10.5f;

int
main()
{
    puts("main starts...");       // main starts...
    Test x;                       // Test::Test()
    std::cout << Test::w << '\n'; // 0
    std::cout << Test::z << '\n'; // 10.5
    puts("main ends...");         // main ends...
}
// Test::~Test()
// ~Value(24)
// ~Value(42)
