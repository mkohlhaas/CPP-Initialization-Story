
#include <iostream>
#include <memory>
#include <string_view>

struct S
{
    int    zero{};  // fine, value initialization
    int    a = 10;  // fine, copy initialization
    double b{10.5}; // fine, brace initialization
    // short c ( 100 );   // err, direct initialization
    int d{zero + a}; // dependency, fine
    // double e { *mem * 2.0 }; // undefined!
    int                   *mem    = new int(d); // only for demo, use smart pointers...
    std::unique_ptr<int[]> pInts  = std::make_unique<int[]>(10);
    long                   arr[4] = {0, 1, 2, 3};
    // long arr2[] = { 1, 2 }; // cannot deduce
    // auto f = 1;     // err, type deduction doesn't work
    double g{compute()};
    // int& ref { }; // error, cannot set ref to null!
    int &refOk{zero};

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
    std::cout << "*.mem: " << *s.mem << '\n';
    std::cout << ".arr[0]: " << s.arr[0] << '\n';
    std::cout << "g:     " << s.g << '\n';
}

int
main()
{
    S s;    // default initialization
    showProperties("s", s);

    S y{1}; // aggregate initialization
    showProperties("y", y);
}
