#include <print>
#include <stdexcept>

constexpr int LOWEST_ID_VALUE = -100;

class Product
{
  private:
    int         id_;
    std::string name_;

  public:
    Product(int id, const std::string &name) : id_{id}, name_{name}
    {
        std::println("Product: {}, {}", id_, name_);
        if (id_ < LOWEST_ID_VALUE)
        {
            throw std::invalid_argument{"id cannot be lower than LOWEST_ID_VALUE!"};
        }
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
    try
    {
        Product car(10, "car");                 // Product: 10, car
        std::println("{} created", car.Name()); // car created

        Product box(-101, "box");               // Product: -101, box
        std::println("{} created", box.Name());
    }
    catch (const std::exception &ex)
    {
        std::println("Error - {}", ex.what()); // Error - id cannot be lower than LOWEST_ID_VALUE!
    }
}
