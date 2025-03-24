#include <iostream>
#include <print>
#include <vector>

// initializer-list creates additional copies

class Value
{
  public:
    int v{0};

    Value(int x) : v(x)
    {
        std::cout << "Value(" << v << ")\n";
    }

    // copy constructor
    Value(const Value &rhs) : v{rhs.v}
    {
        std::cout << "copy Value(" << v << ")\n";
    }

    // move constructor
    Value(Value &&rhs) noexcept : v{rhs.v}
    {
        std::cout << "move Value(" << v << ")\n";
    }

    ~Value() noexcept
    {
        std::cout << "~Value(" << v << ")\n";
    }
};

int
main()
{
    // initializer list
    std::vector<Value> vals{
        1, // Value(1); copy Value(1); ~Value(1)
        2, // Value(2); copy Value(2); ~Value(2)
    };

    std::println();

    std::vector<Value> moreVals;
    moreVals.reserve(4);

    std::cout << "with emplace... \n";
    moreVals.emplace_back(3); // Value(3)
    moreVals.emplace_back(4); // Value(4)

    std::println();

    std::cout << "with push... \n";
    moreVals.push_back(5); // Value(5); move Value(5); ~Value(5)
    moreVals.push_back(6); // Value(6); move Value(6); ~Value(6)

    std::println();
}
