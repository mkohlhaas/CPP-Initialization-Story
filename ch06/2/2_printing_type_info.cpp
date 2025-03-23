#include <iostream>

template <typename T>
constexpr auto
type_name() -> std::string_view
{
    constexpr auto prefix   = std::string_view{"with T = "};
    constexpr auto function = std::string_view{__PRETTY_FUNCTION__};
    const auto     start    = function.find(prefix) + prefix.size();
    return function.substr(start, function.find("; ") - start);
}

template <typename T, typename... Ts>
void
typeNames(const char *str)
{
    std::cout << str;
    std::cout << type_name<T>();
    ((std::cout << ", " << type_name<Ts>()), ...);
}

int
main()
{
    int        num   = 42;
    int       &rnum  = num;
    const int &crnum = num;

    auto c{num};                                                       // int
    auto c2{rnum};                                                     // int
    auto c3{crnum};                                                    // int
    typeNames<decltype(c), decltype(c2), decltype(c3)>("c, c2, c3: "); // c, c2, c3: int, int, int

    auto x{42};                                                        // int
    auto y = 42;                                                       // int
    auto z = {42};                                                     // initializer_list<int>!
    typeNames<decltype(x), decltype(y), decltype(z)>("\nx, y, z: ");   // x, y, z: int, int, std::initializer_list<int>

    struct Object
    {
        std::string str;
    };

    const Object  unknown{"unknown"};                         // const Object
    const Object &refunknown = unknown;                       // const Object &

    auto &&u    = unknown;                                    // const Object &
    auto &&refu = refunknown;                                 // const Object &
    typeNames<decltype(u), decltype(refu)>("\nu and refu: "); // u and refu: const Object&, const Object&
}
