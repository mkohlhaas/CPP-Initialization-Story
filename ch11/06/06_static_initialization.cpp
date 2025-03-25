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

double z = 100.0; //
int    x;         // is initialized to 0
Value  v{42};     // Value(42)

int
main()
{
    puts("main starts..."); // main starts...
    std::cout << x << '\n'; // 0
    puts("main ends...");   // main ends...
}
// ~Value(42)
