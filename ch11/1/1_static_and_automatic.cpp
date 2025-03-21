
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

Value v{42};

int
main()
{
    puts("main starts...");
    Value x{100};
    puts("main ends...");
}
