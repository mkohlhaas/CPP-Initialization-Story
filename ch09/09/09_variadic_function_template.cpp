#include <iostream>
#include <map>
#include <string>
#include <vector>

class Product
{
  public:
    Product() = default;

    Product(std::string s, double v) : name{std::move(s)}, value{v}
    {
    }

    std::string name;
    double      value{};
};

class Package
{
  private:
    std::vector<Product>            prods_;
    std::map<std::string, unsigned> counts_;
    double                          totalValue_{};

  public:
    Package() = default;

    Package(std::initializer_list<Product> items)
    {
        for (auto &elem : items)
        {
            addProduct(elem);
        }
    }

    void
    addProduct(const Product &p)
    {
        ++counts_[p.name];
        prods_.push_back(p);
        totalValue_ += p.value;
    }

    template <typename... Ts>
        requires(std::same_as<Ts, Product> && ...)
    void
    addProducts(const Product &first, const Ts &...args)
    {
        addProduct(first);
        (addProduct(args), ...);
    }

    void
    printContents() const
    {
        for (auto &[key, val] : counts_)
        {
            std::cout << key << ", count: " << val << '\n';
        }
        std::cout << "total value: " << totalValue_ << '\n';
    }
};

int
main()
{
    Package pack;

    // clang-format off
    pack.addProducts(Product{"crayons", 3.0},
                     Product{"pen", 2.0},
                     Product{"bricks", 11.0},
                     Product{"bricks", 12.0},
                     Product{"pen", 12.0},
                     Product{"pencil", 12.0},
                     Product{"pen", 10});
    // clang-format on

    pack.printContents();
}

// bricks, count: 2
// crayons, count: 1
// pen, count: 3
// pencil, count: 1
// total value: 62
