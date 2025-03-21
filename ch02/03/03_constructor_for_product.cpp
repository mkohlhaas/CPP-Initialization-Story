#include <print>
#include <string>

class Product
{
  private:
    int         id_;
    std::string name_;

  public:
    // default constructor
    Product() : id_{-1}, name_{"none"}
    {
    }

    // Non-static data members are initialized in the order they were declared
    // in the class definition (regardless of the order of the mem-initializers).

    // Const references (const T&) can bind to "temporary" objects like a string literal "super car".
    // Without a const reference, we would have to pass some named string object.

    Product(int id, const std::string &name) : id_{id}, name_{name}
    {
    }

    int
    Id() const
    {
        return id_;
    }

    std::string
    Name() const
    {
        return name_;
    }
};

int
main()
{
    Product none;                                     // uses default constructor
    std::println("{}, {}", none.Id(), none.Name());   // -1, none

    Product car(10, "super car");                     // direct initialization
    std::println("{}, {}", car.Id(), car.Name());     // 10, super car

    Product tvSet{77, "tv set"};                      // (direct) list/uniform/brace initialization
    std::println("{}, {}", tvSet.Id(), tvSet.Name()); // 77, tv set
}
