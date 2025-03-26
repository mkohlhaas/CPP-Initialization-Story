#include <iostream>

class InstanceCounter
{
    static inline size_t counter_{0};

  public:
    InstanceCounter() noexcept
    {
        ++counter_;
    }

    InstanceCounter(const InstanceCounter &) noexcept
    {
        ++counter_;
    }

    InstanceCounter(InstanceCounter &&) noexcept
    {
        ++counter_;
    }

    ~InstanceCounter() noexcept
    {
        --counter_;
    }

    static size_t
    getInstanceCounter()
    {
        return counter_;
    }
};

struct Value : InstanceCounter
{
    int val{0};
};

struct Wrapper : InstanceCounter
{
    double val{0.0};
};

int
main()
{
    Value   v;
    Wrapper w;

    std::cout << "Values: " << Value::getInstanceCounter() << '\n';     // Values: 2
    std::cout << "Wrappers: " << Wrapper::getInstanceCounter() << '\n'; // Wrappers: 2
}
