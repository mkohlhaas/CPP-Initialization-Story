
#include <exception>
#include <iostream>
#include <memory>
#include <string>

constexpr int MIN_ID = 100;

struct Resource
{
    Resource() = default;
    ~Resource()
    {
        std::cout << "~Resource\n";
    }
};

class Product
{
  public:
    explicit Product(int id) : res_(std::make_unique<Resource>())
    {
        std::cout << "Product: id " << id << '\n';
        if (id < MIN_ID)
        {
            throw std::runtime_error{"bad id..."};
        }
    }

    ~Product()
    {
        std::cout << "~Product...\n";
    }

  private:
    std::unique_ptr<Resource> res_;
};

int
main()
{
    try
    {
        Product invalid(MIN_ID - 1);
    }
    catch (const std::exception &ex)
    {
        std::cout << "exception: " << ex.what() << '\n';
    }
}
