#include <print>
#include <string>

class Product
{
  public:
    Product() : id_{0}
    {
        std::println("Product() default");
    }

    explicit Product(int id) : id_{id}, name_{}
    {
        std::println("Product(): {} {}", id_, name_);
    }

    explicit Product(int id, const std::string &name) : id_{id}, name_{name}
    {
        std::println("Product(): {} {}", id_, name_);
    }

  protected:
    int         id_;
    std::string name_;
};

class ExProduct : public Product
{
  public:
    ExProduct()
    {
        std::println("ExProduct() default");
    }

    explicit ExProduct(int id)
    {
        id_ = id;
        std::println("ExProduct(id)");
    }
};

int
main()
{
    ExProduct p;          // Product() default
                          // ExProduct() default

    ExProduct withId{42}; // Product() default
                          // ExProduct(id)
}
