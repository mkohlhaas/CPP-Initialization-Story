#include <print>
#include <string>

class Product
{
  public:
    Product(int id, const std::string &name) : id_{id}, name_{name}
    {
        std::println("Product():                {}, {}", id_, name_);
    }

    // move constructor
    Product(Product &&other) : id_{other.id_}, name_{std::move(other.name_)}
    {
        std::println("Product(move):            {}, {}", id_, name_);
    }

    // move assignment
    Product &
    operator=(Product &&other)
    {
        id_   = other.id_;
        name_ = std::move(other.name_);
        std::println("operator=(move):          {}, {}", id_, name_);
        return *this;
    }

    const std::string &
    name() const
    {
        return name_;
    }

  private:
    int         id_;
    std::string name_;
};

int
main()
{
    Product base{42, "base"};                                    // Product():                42, base

    std::println();

    Product first{std::move(base)};                              // Product(move):            42, base
    std::println("base.name() after move: {}", base.name());     // base.name() after move:

    std::println();

    Product second = std::move(first);                           // Product(move):            42, base
    std::println("first.name() after move: {}", first.name());   // first.name() after move:

    std::println();

    Product third{100, "third"};                                 // Product():                100, third
    third = std::move(second);                                   // operator=(move):          42, base
    std::println("second.name() after move: {}", second.name()); // second.name() after move:
}
