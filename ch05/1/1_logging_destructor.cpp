#include <print>
#include <string>

class Product
{
  public:
    explicit Product(const char *name, unsigned id) : name_(name), id_(id)
    {
        std::println("{}, id {}", name, id);
    }

    ~Product()
    {
        std::println("{} destructor...", name_);
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

int
main()
{
    {
        Product tvset("TV Set", 123); // TV Set, id 123
    } // TV Set destructor...

    {
        Product car("Mustang", 999); // Mustang, id 999
    } // Mustang destructor...
}
