#include <iostream>
#include <string>

constexpr double ToWattsRatio{745.699872};

class HorsePower;

class WattPower
{
  public:
    WattPower() = default;

    // constructors must be explicit
    explicit WattPower(double p) : power_{p}
    {
    }

    explicit WattPower(const HorsePower &h);

    double
    getValue() const
    {
        return power_;
    }

  private:
    double power_{0.};
};

class HorsePower
{
  public:
    HorsePower() = default;

    // constructors must be explicit
    explicit HorsePower(double p) : power_{p}
    {
    }

    explicit HorsePower(const WattPower &w);

    double
    getValue() const
    {
        return power_;
    }

  private:
    double power_{0.};
};

// hp to W
WattPower::WattPower(const HorsePower &h) : power_{h.getValue() * ToWattsRatio}
{
}

// W to hp
HorsePower::HorsePower(const WattPower &w) : power_{w.getValue() / ToWattsRatio}
{
}

std::ostream &
operator<<(std::ostream &os, const WattPower &w)
{
    os << w.getValue() << "W";
    return os;
}

std::ostream &
operator<<(std::ostream &os, const HorsePower &h)
{
    os << h.getValue() << "hp";
    return os;
}

struct CarInfo
{
    std::string name;
    unsigned    year;
    unsigned    seats;
    HorsePower  power;
};

void
printInfo(const CarInfo &c)
{
    std::cout << c.name << ", " << c.year << " year, " << c.seats << " seats, " << c.power << '\n';
}

int
main()
{
    CarInfo firstCar{"Megane", 2003, 5, HorsePower{116}}; //
    printInfo(firstCar);                                  // Megane, 2003 year, 5 seats, 116hp

    CarInfo superCar{"Ferrari", 2022, 2, HorsePower{300}};
    printInfo(superCar);                                  // Ferrari, 2022 year, 2 seats, 300hp

    superCar.power = HorsePower{WattPower{500000}};
    printInfo(superCar);                                  // Ferrari, 2022 year, 2 seats, 670.511hp
}
