
#include <iostream>
#include <string>

struct Name
{
    explicit Name(const std::string &str) : name_{str}
    {
    }
    Name(const Name &) = delete;
    std::string name_;
};

class Product
{
  public:
    Product(int id, const std::string &name) : id_{id}, name_{name}
    {
        std::cout << "Product(): " << id_ << ", " << name_.name_ << '\n';
    }

  private:
    int  id_;
    Name name_;
};

int
main()
{
    Product first{10, "basic"};
    Product second{first};
}
