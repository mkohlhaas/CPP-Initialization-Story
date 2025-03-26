#include <iostream>
#include <optional>

using std::optional;
using std::string;

int
main()
{
    optional<double> empty;
    optional<string> ostr{"Hello World"};
    optional<int>    oi{10};

    // has_value()
    if (empty.has_value())
    {
        std::cout << *empty << '\n';
    }
    else
    {
        std::cout << "empty is empty\n"; // empty is empty
    }

    // operator bool
    if (ostr)
    {
        std::cout << *ostr << '\n';     // Hello World
    }
    else
    {
        std::cout << "ostr is empty\n"; //
    }

    // value_or()
    std::cout << oi.value_or(42) << '\n'; // 10
}
