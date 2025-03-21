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
    CarInfo firstCar;

    firstCar.name  = "Renault Megane";
    firstCar.year  = 2002;
    firstCar.seats = 5;
    firstCar.power = 116;

    std::println("name: {}", firstCar.name);     // name: Renault Megane
    std::println("year: {}", firstCar.year);     // year: 2002
    std::println("seats: {}", firstCar.seats);   // seats: 5
    std::println("power: {}hp", firstCar.power); // power: 116hp
}
