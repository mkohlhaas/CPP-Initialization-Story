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

    Product(Product &&other) : id_{other.id_}, name_{std::move(other.name_)}
    {
        std::cout << "Product(move): " << id_ << ", " << name_ << '\n';
    }

    Product &
    operator=(Product &&other)
    {
        id_   = other.id_;
        name_ = std::move(other.name_);
        std::cout << "operator=(move): " << id_ << ", " << name_ << '\n';
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
    Product base{42, "base"};          // ctor called
    std::println();
    Product first{std::move(base)};    // move ctor called!
    std::cout << "base.name() after move: " << base.name() << '\n';
    std::println();
    Product second = std::move(first); // move ctor called!
    std::cout << "first.name() after move: " << first.name() << '\n';
    std::println();
    Product third{100, "third"};
    third = std::move(second);         // assignment operator called!
    std::cout << "second.name() after move: " << second.name() << '\n';
}
