
#include <array>
#include <iostream>
#include <string>

class Product
{
  public:
    Product(int id, const std::string &name) : id_{id}, name_{name}
    {
        std::cout << "Product(): " << id_ << ", " << name_ << '\n';
    }

    Product(const Product &other) : id_{other.id_}, name_{other.name_}
    {
        std::cout << "Product(copy): " << id_ << ", " << name_ << '\n';
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
    return {101, "from createProduct()"};
}

int
main()
{
    std::cout << "calling createProduct()\n";
    Product created = createProduct();
}
