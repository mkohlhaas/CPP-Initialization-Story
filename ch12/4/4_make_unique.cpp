#include <memory>

struct Point
{
    int x;
    int y;
};

int
main()
{
    // works only in C++20
    auto ptr = std::make_unique<Point>(10, 20);
}
