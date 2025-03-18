
#include <iostream>
#include <string>

struct CarInfo
{
    std::string name{"unknown"};
    unsigned    year{1920};
    unsigned    seats{4};
    double      power{100.};
};

void
printInfo(const CarInfo &c)
{
    std::cout << c.name << ", " << c.year << " year, " << c.seats << " seats, " << c.power << " hp\n";
}

int
main()
{
    CarInfo unknown;
    printInfo(unknown);
    CarInfo zeroed{};
    printInfo(zeroed);
    CarInfo partial{"large car", 1975};
    printInfo(partial);
}
