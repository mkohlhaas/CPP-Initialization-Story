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

// global var
Value v{42}; // Value(42)

int
main()
{
    puts("main starts..."); // main starts...
    Value x{100};           // Value(100)
    puts("main ends...");   // main ends...
}
// ~Value(100)
// ~Value(42)
