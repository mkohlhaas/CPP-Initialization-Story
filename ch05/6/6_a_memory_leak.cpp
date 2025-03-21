#include <exception>
#include <print>

constexpr int MIN_ID = 100;

struct Resource
{
    Resource() = default;

    ~Resource()
    {
        std::println("~Resource");
    }
};

class Product
{
  public:
    explicit Product(int id) : res_(new Resource())
    {
        std::println("Product: id {}", id);
        if (id < MIN_ID)
        {
            throw std::runtime_error{"bad id..."};
        }
    }

    ~Product()
    {
        delete res_;
        std::println("~Product...");
    }

  private:
    Resource *res_;
};

int
main()
{
    try
    {
        Product invalid(MIN_ID - 1);              // Product: id 99
    }
    catch (const std::exception &ex)
    {
        std::println("exception: {}", ex.what()); // exception: bad id...
    }
}
