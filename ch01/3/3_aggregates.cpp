#include <print>

struct Point
{
    int x;
    int y;
};

struct Line
{
    Point p1;
    Point p2;
};

int
main()
{
    // arrays:
    int   arr[]{1, 2, 3, 4};
    float numbers[] = {0.1f, 1.1f, 2.2f, 3.f, 4.f, 5.};
    int   nums[10]{1};

    // structures:
    Line longLine{0, 0, 100, 100};
    Line anotherLine = {100};
    Line shortLine{{-10, -10}, {10, 10}};
    // Line shortLine{{}, {}};
    // Line shortLine{};

    // print the whole stuff

    for (auto i : arr)
    {
        std::print("{} ", i); // 1 2 3 4
    }

    std::println();

    for (auto i : numbers)
    {
        std::print("{} ", i); // 0.1 1.1 2.2 3 4 5
    }

    std::println();

    for (auto i : nums)
    {
        std::print("{} ", i); // 1 0 0 0 0 0 0 0 0 0
    }

    std::println();

    std::println("{}", longLine.p1.x);    // 0
    std::println("{}", longLine.p1.y);    // 0
    std::println("{}", longLine.p2.x);    // 100
    std::println("{}", longLine.p2.y);    // 100

    std::println("{}", anotherLine.p1.x); // 100
    std::println("{}", anotherLine.p1.y); // 0
    std::println("{}", anotherLine.p2.x); // 0
    std::println("{}", anotherLine.p2.y); // 0

    std::println("{}", shortLine.p1.x);   // -10
    std::println("{}", shortLine.p1.y);   // -10
    std::println("{}", shortLine.p2.x);   // 10
    std::println("{}", shortLine.p2.y);   // 10
}
