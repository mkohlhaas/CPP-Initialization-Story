#include <iostream>

template <typename Derived>
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

// Values and Wrapper have their own instance counter.

// CRTP
struct Value : InstanceCounter<Value>
{
    int val{0};
};

// CRTP
struct Wrapper : InstanceCounter<Wrapper>
{
    double val{0.0};
};

int
main()
{
    Value   v;
    Wrapper w;

    std::cout << "Values: " << Value::getInstanceCounter() << '\n';     // Values: 1
    std::cout << "Wrappers: " << Wrapper::getInstanceCounter() << '\n'; // Wrappers: 1
}
