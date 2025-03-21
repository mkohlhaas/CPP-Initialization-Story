#include <print>
#include <string>

class Product
{
  public:
    Product(int id, const std::string &name) : id_{id}, name_{name}
    {
        std::println("Product(): ", id_, name_);
    }

    Product(const Product &other) : id_{other.id_}, name_{other.name_}
    {
        std::println("Product(copy): ", id_, name_);
    }

    Product &
    operator=(const Product &other)
    {
        if (this == &other)
        {
            return *this;
        }

        id_   = other.id_;
        name_ = other.name_;

        std::println("operator=(copy): ", id_, name_);
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
    Product base{42, "base"};    // Product(): 42, base

    Product first{base};         // Product(copy): 42, base

    Product second = first;      // Product(copy): 42, base

    Product third{100, "third"}; // Product(): 100, third

    third = second;              // operator=(copy): 42, base
}
