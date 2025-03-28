#include <array>

struct Array
{
    int data[2];
};

struct Matrix
{
    Array arr[2];
};

// similar structure based on std::array
using Matrix1 = std::array<std::array<int, 2>, 2>;

int
main()
{
    [[maybe_unused]] Matrix mat1{1, 2, 3, 4};       // fine
    [[maybe_unused]] Matrix mat2{{1, 2, 3, 4}};     // fine
    [[maybe_unused]] Matrix mat3{{{1, 2}, {3, 4}}}; // fine, full form

    // Matrix mat4 { {1, 2}, {3, 4} };     // doesn't compile!
}
