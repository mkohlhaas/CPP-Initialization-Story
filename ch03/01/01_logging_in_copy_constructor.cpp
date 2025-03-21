#include <array>
#include <iostream>
#include <print>
#include <string>

class Product
{
  public:
    Product(int id, const std::string &name) : id_{id}, name_{name}
    {
        std::println("Product(): {}, {}", id_, name_);
    }

    Product(const Product &other) : id_{other.id_}, name_{other.name_}
    {
        std::println("Product(copy): {}, {}", id_, name_);
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

void
foo(Product)
{
    std::println("inside foo()");
}

Product
createProduct()
{
    return Product{101, "from createProduct()"};
}

int
main()
{
    Product base{42, "base product"};                            // Product(): 42, base product
    std::println("{} created", base.Name());                     // base product created
    std::println("Product other {{ base }};");                   // Product other { base };

    std::println();

    Product other{base};                                         // Product(copy): 42, base product
    std::println("Product another(base);");                      // Product another(base);

    std::println();

    Product another(base);                                       // Product(copy): 42, base product
    std::println("Product oneMore = base;");                     // Product oneMore = base;

    std::println();

    Product oneMore = base;                                      // Product(copy): 42, base product
    std::println("std::array<Product, 2> = {{ base, other }};"); // std::array<Product, 2> = { base, other };

    std::println();

    std::array<Product, 2> arr = {base, other};                  // Product(copy): 42, base product
                                                                 // Product(copy): 42, base product
    std::println();

    std::println("calling foo()");                               // calling foo()
    foo(arr[0]);                                                 // Product(copy): 42, base product
                                                                 // inside foo()
    std::println();

    std::println("calling createProduct()");                     // calling createProduct()
    Product created = createProduct();                           // Product(): 101, from createProduct()
}
