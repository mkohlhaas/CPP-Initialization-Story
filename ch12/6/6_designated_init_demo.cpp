#include <iostream>
#include <string>

using std::string;

struct Product
{
    string name_;
    bool   inStock_{false};
    double price_ = 0.0;
};

void
Print(const Product &p)
{
    std::cout << std::boolalpha;
    std::cout << "name: " << p.name_ << ", in stock: " << p.inStock_ << ", price: " << p.price_ << '\n';
}

struct Time
{
    int hour;
    int minute;
};

struct Date
{
    Time t;
    int  year;
    int  month;
    int  day;
};

int
main()
{
    Product p1{.name_ = "box", .inStock_{true}};  //
    Print(p1);                                    // name: box, in stock: true, price: 0

    Product p2{.name_ = "box", .inStock_ = true}; //
    Print(p2);                                    // name: box, in stock: true, price: 0

    [[maybe_unused]] Date d{.t{.hour = 10, .minute = 35}, .year = 2050, .month = 5, .day = 10};

    // pass to a function:
    Print({.name_ = "tv", .inStock_{true}, .price_{100.0}});   // name: tv, in stock: true, price: 100
    Print({.name_ = "tv", .inStock_ = true, .price_ = 100.0}); // name: tv, in stock: true, price: 100

    // not all members used:
    Print({.name_ = "car", .price_{2000.0}});  // name: car, in stock: false, price: 2000
    Print({.name_ = "car", .price_ = 2000.0}); // name: car, in stock: false, price: 2000
}
