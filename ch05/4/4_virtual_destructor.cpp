
#include <iostream>
#include <memory>
#include <string>

class Product
{
  public:
    explicit Product(const char *name) : name_(name)
    {
        std::cout << name << '\n';
    }

    ~Product()
    {
        std::cout << name_ << " destructor...\n";
    }

    std::string
    Name() const
    {
        return name_;
    }

    virtual double CalculateMass() const = 0;

  private:
    std::string name_;
};

struct BoxProduct : public Product
{
    using Product::Product; // inheriting ctor
    ~BoxProduct()
    {
        std::cout << "~BoxProduct...\n";
    }

    double
    CalculateMass() const override
    {
        return 10.0;
    }
};

struct FluidProduct : public Product
{
    using Product::Product; // inheriting ctor
    ~FluidProduct()
    {
        std::cout << "~FluidProduct...\n";
    }

    double
    CalculateMass() const override
    {
        return 100.0;
    }
};

void
CallCalculate(const Product &prod)
{
    std::cout << "calculating: " << prod.CalculateMass() << '\n';
}

int
main()
{
    using std::make_unique;
    using std::unique_ptr;
    unique_ptr<Product> box   = make_unique<BoxProduct>("box");
    unique_ptr<Product> water = make_unique<FluidProduct>("water");
    CallCalculate(*box.get());
    CallCalculate(*water.get());
}
