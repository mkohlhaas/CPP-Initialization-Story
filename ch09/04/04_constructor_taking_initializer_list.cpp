#include <initializer_list>
#include <iostream>
#include <print>

// All containers from the Standard Library have constructors supporting initializer_list.
// (Implemented similar to class X.)

class X
{
  public:
    size_t count{};

    X(std::initializer_list<int> list) : count{list.size()}
    {
        puts("X(init_list)");
    }

    X(size_t cnt) : count{cnt}
    {
        puts("X(cnt)");
    }

    X()
    {
        puts("X()");
    }
};

int
main()
{
    X x;
    std::cout << "x.count = " << x.count << '\n';

    std::println();

    // the list constructor takes precedence over the regular constructor taking one argument
    X y{1};
    std::cout << "y.count = " << y.count << '\n';

    std::println();

    X z{1, 2, 3, 4};
    std::cout << "z.count = " << z.count << '\n';

    std::println();

    // to call the exact constructor, you need to use direct initialization with parens ()
    X w(3);
    std::cout << "w.count = " << w.count << '\n';
}
