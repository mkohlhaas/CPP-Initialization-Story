#include <iostream>
#include <thread>

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

void
foo()
{
    static Value x{10}; // thread-safe initialization (done only once)
}

int
main()
{
    std::jthread worker1{foo};
    std::jthread worker2{foo};
    std::jthread worker3{foo};
}

// Value(10)
// ~Value(10)
