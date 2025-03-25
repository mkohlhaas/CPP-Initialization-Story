#include <iostream>
#include <string>
#include <vector>

// Constant non-static data members
//
// - It will be default constructible only when you assign a default value to the member (NSDMI);
//   otherwise, it won’t be default constructible.
// - The compiler can generate a copy and move constructors.
// - Default copy assignment and move assignment operators are blocked.

// If you want your object to be constant, make it const as a "whole" rather than just some of its parts.

class Product
{
  private:
    std::string    name_; //
    const unsigned id_;   // const data member

  public:
    // Product() = default;  // id_ is const -> explicitly defaulted default constructor is implicitly deleted

    explicit Product(const char *name, unsigned id) : name_(name), id_(id)
    {
    }

    const std::string &
    name() const
    {
        return name_;
    }

    void
    name(const std::string &name)
    {
        name_ = name;
    }

    unsigned
    id() const
    {
        return id_;
    }
};

int
main()
{
    Product tvset("TV Set", 123);
    std::cout << tvset.name() << ", id: " << tvset.id() << '\n'; // TV Set, id: 123

    // id_ is const -> Object of type 'Product' cannot be assigned because
    // its copy assignment operator is implicitly deleted
    //
    // tvset = Product("TV Set 2022", 456);

    std::vector<Product> prods;
    prods.push_back(Product("box", 234)); // OK
    prods.push_back(Product("car", 567));
    // prods.insert(prods.begin(), Product("ball", 987)); // error: .insert() needs copy assighment operator
}
