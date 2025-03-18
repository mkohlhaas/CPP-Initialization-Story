#include <iostream>
#include <print>
#include <string>

class Product
{
  public:
    Product(int id, const std::string &name) : id_{id}, name_{name}
    {
        std::cout << "Product(): " << id_ << ", " << name_ << '\n';
    }

    Product(const Product &other) : id_{other.id_}, name_{other.name_}
    {
        std::cout << "Product(copy): " << id_ << ", " << name_ << '\n';
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
        std::cout << "operator=(copy): " << id_ << ", " << name_ << '\n';
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
    Product base{42, "base"};
    std::println();
    Product first{base};    // copy ctor called!
    std::println();
    Product second = first; // copy ctor called!
    std::println();
    Product third{100, "third"};
    std::println();
    third = second;         // assignment operator called!
}
