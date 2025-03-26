#include <array>
#include <iostream>

// Arrays and simple structures with all public data members are called Aggregates.

using std::string;

struct Base
{
    int x{42};
};

struct Derived : Base
{
    int y;
};

struct Param
{
    string name;
    int    val;

    void parse(); // member functions allowed
};

int
main()
{
    Derived d1{100, 1000};                                             //
    std::cout << "d1.x: " << d1.x << ", d1.y: " << d1.y << '\n';       // d1.x: 100, d1.y: 1000

    Derived d2{1};                                                     //
    std::cout << "d2.x: " << d2.x << ", d2.y: " << d2.y << '\n';       // d2.x: 1, d2.y: 0

    Param p{"value", 10};
    std::cout << "p.name: " << p.name << ", p.val: " << p.val << '\n'; // p.name: value, p.val: 10

    double arr[]{1.1, 2.2, 3.3, 4.4};
    std::cout << "arr[0]: " << arr[0] << '\n';                         // arr[0]: 1.1

    std::array floats{10.1f, 20.2f, 30.3f};
    std::cout << "floats[0]: " << floats[0] << '\n';                   // floats[0]: 10.1

    std::array params{Param{"val", 10}, Param{"name", 42}};
    std::cout << "params[0].name: " << params[0].name << '\n';         // params[0].name: val
}
