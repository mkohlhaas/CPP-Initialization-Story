#include <print>
#include <string>

class Product
{
  public:
    Product(int id, unsigned quantity, const std::string &name) : id_{id}, quantity_{quantity}, name_{name}
    {
        verifyData();
    }

    // delegating constructor
    Product(const std::string &name, int id = 0) : Product{id, 0, name}
    {
    }

    void
    verifyData()
    {
        if (quantity_ > MaxQuantity)
        {
            throw std::invalid_argument("qantity is too large!");
        }
    }

    std::string
    getName() const
    {
        return name_;
    }

    int
    getId() const
    {
        return id_;
    }

  private:
    int         id_;
    unsigned    quantity_;
    std::string name_;

    static constexpr unsigned MaxQuantity = 100;
};

int
main()
{
    try
    {
        Product box{"a box"};
        std::println("product: {} created...", box.getName()); // product: a box created...

        Product toy{101, 200, "a box"};
        std::println("product: {} created...", toy.getName()); // error
    }
    catch (const std::exception &e)
    {
        std::println("cannot create: {}", e.what());           // cannot create: qantity is too large!
    }
}
