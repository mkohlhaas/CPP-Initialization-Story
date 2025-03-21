#include <print>
#include <string>

class Product
{
  public:
    Product(int id, const std::string &name) : id_{id}, name_{name}
    {
        std::println("Product(): " << id_ << ", " << name_ << '\n';
    }

    Product(Product &&other) noexcept : id_{other.id_}, name_{std::move(other.name_)}
    {
        std::println("Product(move): " << id_ << ", " << name_ << '\n';
    }

    Product
    operator+(const std::string s)
    {
        return Product{id_, name_ + s};
    }

    std::string
    Name() const
    {
        return name_;
    }

  private:
    int         id_;
    std::string name_;
};

int
main()
{
    Product tvSet1{100, "tv set"};                // Product(): 100, tv set
    std::println("{} created...", tvSet1.Name()); // tv set created...

    Product tvSet2{std::move(tvSet1)};            // Product(move): 100, tv set
    std::println("{} created...", tvSet2.Name()); // tv set created...
    std::println("old value: {}", tvSet1.Name()); // old value:
}
