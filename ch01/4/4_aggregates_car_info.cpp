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
printInfo(const CarInfo &c)
{
    std::println("{}, {} year, {} seats, {} hp", c.name, c.year, c.seats, c.power);
}

int
main()
{
    CarInfo firstCar{"Megane", 2003, 5, 116}; //
    printInfo(firstCar);                      // Megane, 2003 year, 5 seats, 116 hp

    CarInfo partial{"unknown"};               //
    printInfo(partial);                       // unknown, 0 year, 0 seats, 0 hp

    CarInfo largeCar{"large car", 1975, 10};  //
    printInfo(largeCar);                      // large car, 1975 year, 10 seats, 0 hp
}
