#include <iostream>

struct Type
{
    // bit fields (of size 4)
    int value : 4 = 1;
    int second : 4 {2};
};

int
main()
{
    Type t;
    std::cout << t.value << '\n';  // 1
    std::cout << t.second << '\n'; // 2
}
