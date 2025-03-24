#include <iostream>
#include <map>
#include <string>
#include <vector>

//  For std::initializer_list the compiler deduces the size and creates a C-style array
//  underneath for its elements, so there are no extra allocations here.

class Product
{
  public:
    std::string name;
    double      value{};

    Product() = default;

    Product(std::string s, double v) : name{std::move(s)}, value{v} // using move
    {
    }
};

class Package
{
    using map_prod_count = std::map<std::string, unsigned>;
    using vec_prods      = std::vector<Product>;

  private:
    vec_prods      prods_;
    map_prod_count counts_;
    double         totalValue_{};

  public:
    Package() = default;

    Package(std::initializer_list<Product> items)
    {
        addProducts(items);
    }

    void
    addProduct(const Product &p)
    {
        ++counts_[p.name];
        prods_.push_back(p);
        totalValue_ += p.value;
    }

    void
    addProducts(std::initializer_list<Product> items)
    {
        for (auto &elem : items)
        {
            addProduct(elem);
        }
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
    Package pack({
        {"crayons", 3.0},
        {"pen", 2.0},
        {"bricks", 11.0},
        {"bricks", 12.0},
        {"pen", 12.0},
        {"pencil", 12.0},
    });
    pack.printContents();
}

// bricks, count: 2
// crayons, count: 1
// pen, count: 2
// pencil, count: 1
// total value: 52
