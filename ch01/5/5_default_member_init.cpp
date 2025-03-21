#include <print>
#include <string>

struct CarInfo
{
    std::string name{"unknown"};
    unsigned    year{1920};
    unsigned    seats{4};
    double      power{100};
};

void
printInfo(const CarInfo &c)
{
    std::println("{}, {} year, {} seats, {} hp", c.name, c.year, c.seats, c.power);
}

int
main()
{
    CarInfo unknown;                    //
    printInfo(unknown);                 // unknown, 1920 year, 4 seats, 100 hp

    CarInfo zeroed{};                   //
    printInfo(zeroed);                  // unknown, 1920 year, 4 seats, 100 hp

    CarInfo partial{"large car", 1975}; //
    printInfo(partial);                 // large car, 1975 year, 4 seats, 100 hp
}
