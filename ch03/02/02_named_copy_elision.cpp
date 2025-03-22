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

Product
createProduct()
{
    Product temp{101, "from createProduct()"}; // Product(): 101, from createProduct()
    return temp;
}

int
main()
{
    Product created = createProduct(); // copy constructor not called (copy elision; NRVO)
}
