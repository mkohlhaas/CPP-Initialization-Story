#include <print>
#include <string>

class Product
{
  public:
    explicit Product(int id, const std::string &name) : id_(id), name_(name)
    {
        std::println("Product(): {}, {}", id_, name_);
    }

  private:
    int         id_;
    std::string name_;
};

int
main()
{
    Product first{10, "basic"}; // Product(): 10, basic
}
