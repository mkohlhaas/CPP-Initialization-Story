
#include <initializer_list>
#include <iostream>

struct X
{
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
    size_t count{};
};

int
main()
{
    X x;
    std::cout << "x.count = " << x.count << '\n';
    X y{1};
    std::cout << "y.count = " << y.count << '\n';
    X z{1, 2, 3, 4};
    std::cout << "z.count = " << z.count << '\n';
    X w(3);
    std::cout << "w.count = " << w.count << '\n';
}
