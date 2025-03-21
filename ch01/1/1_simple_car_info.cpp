#include <print>
#include <string>

struct CarInfo
{
    std::string name;
    unsigned    year;
    unsigned    seats;
    double      power;
};

void
print_carinfo(const CarInfo &car)
{
    std::println("name: {}", car.name);
    std::println("year: {}", car.year);
    std::println("seats: {}", car.seats);
    std::println("power: {}hp", car.power);
}

int
main()
{
    CarInfo firstCar;

    print_carinfo(firstCar);
    // name:
    // year: (random value)
    // seats: (random value)
    // power: (random value)hp

    firstCar.name  = "Renault Megane";
    firstCar.year  = 2002;
    firstCar.seats = 5;
    firstCar.power = 116;

    std::println();

    print_carinfo(firstCar);
    // name: Renault Megane
    // year: 2002
    // seats: 5
    // power: 116hp
}
