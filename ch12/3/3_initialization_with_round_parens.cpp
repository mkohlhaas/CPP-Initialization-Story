struct Point
{
    int x;
    int y;
};

struct PointExt
{
    Point pt;
    int   z;
};

int
main()
{

    [[maybe_unused]] Point pt1(1, 2);                             // C++20 can use parens (direct initialization)

    [[maybe_unused]] Point pt2{1, 2};

    [[maybe_unused]] Point pt3 = (1, 2);                          // wrong syntax

    [[maybe_unused]] Point pt4 = {1, 2};

    [[maybe_unused]] Point pt5{1.1, 2.2};                         // narrowing prevented

    [[maybe_unused]] Point pt6(1.1, 2.2);                         // narrowing

    [[maybe_unused]] PointExt pt7{{4, 5}, 6};

    [[maybe_unused]] PointExt pt8{4, 5, 6};                       // brace elision works

    [[maybe_unused]] PointExt pt9((4, 5), 6);                     // nesting doesn't work

    [[maybe_unused]] PointExt pt10(4, 5, 6);                      // brace elision doesn't work

    [[maybe_unused]] PointExt pt11(Point(4, 5), 6);               // need to be explicit

    [[maybe_unused]] double params[](9.81, 3.14, 1.44);           // ✓

    [[maybe_unused]] double paramsDeduced[] = (9.81, 3.14, 1.44); // wrong syntax

    [[maybe_unused]] int arrX[10](1, 2, 3, 4);                    // rest is 0
}
