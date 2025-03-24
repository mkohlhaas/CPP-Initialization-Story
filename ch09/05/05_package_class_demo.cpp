#include <iostream>
#include <map>
#include <string>
#include <vector>

class Product
{
  public:
    std::string name;
    double      value;

    Product() : name{}, value{}
    {
    }

    Product(const std::string &s, double v) : name{s}, value{v}
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
    double         totalValue_;

  public:
    Package()
    {
    }

    void
    addProduct(const Product &p)
    {
        ++counts_[p.name];
        prods_.push_back(p);
        totalValue_ += p.value;
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
    pack.addProduct({"crayons", 3.0}); // adding every single product (tedious)
    pack.addProduct({"pen", 2.0});
    pack.addProduct({"bricks", 11.0});
    pack.addProduct({"bricks", 12.0});
    pack.addProduct({"pen", 12.0});
    pack.addProduct({"pencil", 12.0});
    pack.printContents();
}

// bricks, count: 2
// crayons, count: 1
// pen, count: 2
// pencil, count: 1
// total value: 52
