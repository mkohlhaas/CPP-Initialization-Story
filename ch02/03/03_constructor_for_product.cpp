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
    Product none;
    std::println("{}, {}", none.Id(), none.Name());   // -1, none

    Product car(10, "super car");
    std::println("{}, {}", car.Id(), car.Name());     // 10, super car

    Product tvSet{77, "tv set"};
    std::println("{}, {}", tvSet.Id(), tvSet.Name()); // 77, tv set
}
