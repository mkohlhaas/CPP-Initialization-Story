#include <print>
#include <string>

class Product
{
  public:
    explicit Product(const char *name, unsigned id) : name_(name), id_(id)
    {
        std::println("{}, {}", name, id);
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

class Wrapper
{
  public:
    Wrapper() : prod_("internal", 123)
    {
        std::println("Wrapper()");
    }

    ~Wrapper()
    {
        std::println("~Wrapper()");
    }

  private:
    Product prod_;
};

int
main()
{
    Wrapper w; // internal, id 123
    // Wrapper()

} // ~Wrapper()
  // internal destructor...
