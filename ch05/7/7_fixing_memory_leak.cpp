#include <exception>
#include <memory>
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
    explicit Product(int id) : res_(std::make_unique<Resource>())
    {
        std::println("Product: id {}", id);
        if (id < MIN_ID)
        {
            throw std::runtime_error{"bad id..."};
        }
    }

    ~Product()
    {
        std::println("~Product...");
    }

  private:
    std::unique_ptr<Resource> res_;
};

int
main()
{
    try
    {
        Product invalid(MIN_ID - 1);            // Product: id 99
                                                // ~Resource (wasn't called before)
    }
    catch (const std::exception &ex)
    {
        std::println("exception: ", ex.what()); // exception: bad id...
    }
}
