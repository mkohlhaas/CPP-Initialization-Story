#include <exception>
#include <print>
#include <string>

class Product
{
  public:
    explicit Product(const char *name, unsigned id) : name_(name), id_(id)
    {
        std::println("{}, id {}", name, id);
        if (id < 100)
        {
            throw std::runtime_error{"bad id..."};
        }
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
    try
    {
        Product tvset("TV Set", 123);             // TV Set, id 123 [1]
        Product car("Mustang", 9);                // Mustang, id 9 [2]
    }
    catch (const std::exception &ex)
    {
        std::println("exception: {}", ex.what()); // exception: bad id... [4]
    }
} // TV Set destructor... [3]
