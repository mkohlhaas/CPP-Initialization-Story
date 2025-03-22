#include <array>
#include <print>
#include <string>

class Product
{
  private:
    int         id_;
    std::string name_;

  public:
    Product(int id, const std::string &name) : id_{id}, name_{name}
    {
        std::println("Product():               {}, {}", id_, name_);
    }

    Product(const Product &other) : id_{other.id_}, name_{other.name_}
    {
        std::println("Product(copy):           {}, {}", id_, name_);
    }

    std::string
    Name() const
    {
        return name_;
    }
};

void
foo(Product)
{
    std::println("in foo()");
}

Product
createProduct()
{
    return Product{101, "from createProduct()"};
}

int
main()
{
    Product base{42, "base product"};  // Product(): 42, base product

    Product other{base};               // Product(copy): 42, base product
    Product another(base);             // Product(copy): 42, base product
    Product oneMore = base;            // Product(copy): 42, base product

    std::array arr = {base, other};    // Product(copy): 42, base product
                                       // Product(copy): 42, base product

    foo(arr[0]);                       // Product(copy): 42, base product
                                       // in foo()

    Product created = createProduct(); // Product(): 101, from createProduct()
                                       // copy elision (NRVO = Named Return Value Optimization)
}
