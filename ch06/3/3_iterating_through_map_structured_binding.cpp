#include <iostream>
#include <map>

int
main()
{
    const std::map<std::string, int> mapCityPopulation{
        {"Beijing", 21'707'000},
        {"London", 8'787'892},
        {"New York", 8'622'698},
    };

    // structured bindings
    for (const auto &[city, population] : mapCityPopulation)
    {
        std::cout << city << ": " << population << '\n';
    }
}

// Beijing: 21707000
// London: 8787892
// New York: 8622698
