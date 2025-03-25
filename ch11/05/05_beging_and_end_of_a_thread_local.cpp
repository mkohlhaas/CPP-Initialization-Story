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

thread_local Value x{42};

void
foo()
{
    std::cout << "foo()\n";
    x.v = 100;
}

int
main()
{
    std::cout << "main " << std::this_thread::get_id() << '\n';

    {
        std::jthread worker1{foo};
        std::jthread worker2{foo};
    }

    std::cout << "end main()\n";
}

// main 126286874846784
// foo()
// Value(42)
// ~Value(100)
// foo()
// Value(42)
// ~Value(100)
// end main()

// When you comment out line 25 (x.v = 100):
// main 128730543404608
// foo()
// foo()
// end main()
