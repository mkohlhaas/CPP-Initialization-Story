#include <iostream>

struct Value
{
    int        x;
    static int y; // declaration
};

// like a global variable in the Value namespace
// static storage duration and external linkage
int Value::y = 0; // definition

int
main()
{
    Value v{10};

    std::cout << "sizeof(int): " << sizeof(int) << '\n';     // sizeof(int): 4
    std::cout << "sizeof(Value): " << sizeof(Value) << '\n'; // sizeof(Value): 4
    std::cout << "v.x: " << v.x << '\n';                     // v.x: 10
    std::cout << "Value::y: " << Value::y << '\n';           // Value::y: 0

    Value::y = 10;
    std::cout << "Value::y: " << Value::y << '\n';           // Value::y: 10
}
