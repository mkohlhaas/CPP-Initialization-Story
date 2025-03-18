// ex 5 2 nested destructor calls.cpp
// example for "C++ Initialization Story"
// https://leanpub.com/cppinitbook
// by Bartlomiej Filipek
// 2022
// MIT License

#include <iostream>
#include <string>

class Product
{
  public:
    explicit Product(const char *name, unsigned id) : name_(name), id_(id)
    {
        std::cout << name << ", id " << id << '\n';
    }

    ~Product()
    {
        std::cout << name_ << " destructor...\n";
    }

    std::string
    Name() const
    {
        return name_;
    }
    unsigned
    Id() const
    {
        return id_;
    }

  private:
    std::string name_;
    unsigned    id_;
};

class Wrapper
{
  public:
    Wrapper() : prod_("internal", 123)
    {
        std::cout << "Wrapper()\n";
    }
    ~Wrapper()
    {
        std::cout << "~Wrapper()\n";
    }

  private:
    Product prod_;
};

int
main()
{
    Wrapper w;
}
