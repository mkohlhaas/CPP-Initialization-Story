#include <print>
#include <string>

struct CarInfo
{
    std::string name;
    unsigned    year;
    unsigned    seats;
    double      power;
};

int
main()
{
    CarInfo emptyCar{};

    std::println("name: {}", emptyCar.name);     // name:
    std::println("year: {}", emptyCar.year);     // year: 0
    std::println("seats: {}", emptyCar.seats);   // seats: 0
    std::println("power: {}hp", emptyCar.power); // power: 0hp
}
