#include <iostream>
#include <memory>
#include <string_view>

struct S
{
    int    zero{};                // fine, value initialization
    int    a = 10;                // fine, copy initialization
    double b{10.5};               // fine, brace initialization
    int    d{zero + a};           // dependency, fine
    int   *mem    = new int(d);   // only for demo, use smart pointers...
    long   arr[4] = {0, 1, 2, 3}; //
    double g{compute()};
    int   &refOk{zero};
    double e{*mem * 2.0};

    std::unique_ptr<int[]> pInts = std::make_unique<int[]>(10);

    // short  c(100);          // err, direct initialization
    // long   arr2[] = {1, 2}; // cannot deduce
    // auto   f      = 1;      // err, type deduction doesn't work
    // int   &ref{};           // error, cannot set ref to null!

    ~S()
    {
        delete mem;
    }

    double
    compute()
    {
        return a * b;
    }
};

void
showProperties(std::string_view text, const S &s)
{
    std::cout << text << '\n';
    std::cout << ".zero: " << s.zero << '\n';
    std::cout << ".a:    " << s.a << '\n';
    std::cout << ".b:    " << s.b << '\n';
    std::cout << ".d:    " << s.d << '\n';
    std::cout << ".e:    " << s.e << '\n';
    std::cout << "*.mem: " << *s.mem << '\n';
    std::cout << ".arr[0]: " << s.arr[0] << '\n';
    std::cout << "g:     " << s.g << '\n';
}

int
main()
{
    S s; // default initialization
    showProperties("s", s);

    std::cout << std::endl;

    S y{1};                 // aggregate initialization -> zero = 1
    showProperties("y", y); //
}
