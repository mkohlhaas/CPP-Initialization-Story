#include <print>
#include <string>
#include <vector>

class Product
{
  public:
    Product(int id, const std::string &name) : id_{id}, name_{name}
    {
        std::println("Product():     {}, {}", id_, name_);
    }

    Product(const Product &other) : id_{other.id_}, name_{other.name_}
    {
        std::println("Product(copy): {}, {}", id_, name_);
    }

    Product(Product &&other) : id_{other.id_}, name_{std::move(other.name_)}
    {
        std::println("Product(move): {}, {}", id_, name_);
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
    std::vector<Product> prods;

    prods.emplace_back(101, "car");
    std::println();
    prods.emplace_back(202, "box");
    std::println();
    prods.emplace_back(303, "toy");
    std::println();
    prods.emplace_back(404, "mug");
    std::println();
    prods.emplace_back(505, "pencil");
}
