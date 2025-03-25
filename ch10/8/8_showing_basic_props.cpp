#include <ios>
#include <iostream>
#include <memory>
#include <string>
#include <type_traits>
#include <vector>

// Ref thingies are not default constructable.
// Ref thingies are only assignable when using std::reference_wrapper.
// Unique Pointers can't be copied.
// Const thingies are not assignable.

template <typename T>
void
ShowProps()
{
    std::cout << std::boolalpha;
    std::cout << typeid(T).name() << '\n';
    std::cout << "default constructible " << std::is_default_constructible_v<T> << '\n';
    std::cout << "copy constructible    " << std::is_copy_constructible_v<T> << '\n';
    std::cout << "copy assignable       " << std::is_copy_assignable_v<T> << '\n';
    std::cout << "move constructible    " << std::is_move_constructible_v<T> << '\n';
    std::cout << "move assignable       " << std::is_move_assignable_v<T> << '\n';
    std::cout << std::endl;
}

class Product
{
  public:
    Product() = default;
    explicit Product(std::string name, unsigned id) : name_(std::move(name)), id_(id)
    {
    }

  private:
    std::string               name_;
    [[maybe_unused]] unsigned id_{};
};

class ProductConst
{
  public:
    ProductConst() = default;
    explicit ProductConst(const char *name, unsigned id) : name_(name), id_(id)
    {
    }

  private:
    std::string    name_;
    const unsigned id_{};
};

class ProductRef
{
  public:
    ProductRef() = delete; // compiles, but will be deleted, as the compiler cannot create it...
    explicit ProductRef(std::string name, unsigned &id) : name_(std::move(name)), idRef_(id)
    {
    }

  private:
    std::string                name_;
    [[maybe_unused]] unsigned &idRef_;
};

class ProductConstRef
{
  public:
    ProductConstRef() = delete;
    explicit ProductConstRef(std::string name, const unsigned &id) : name_(std::move(name)), idRef_(id)
    {
    }

  private:
    std::string                      name_;
    [[maybe_unused]] const unsigned &idRef_;
};

class ProductRefWrapper
{
  public:
    ProductRefWrapper() = delete;
    explicit ProductRefWrapper(std::string name, unsigned id) : name_(std::move(name)), idRef_(id)
    {
    }

  private:
    std::string                      name_;
    std::reference_wrapper<unsigned> idRef_;
};

class ProductPointer
{
  public:
    ProductPointer() = default;
    explicit ProductPointer(std::string name, unsigned *pId) : name_(std::move(name)), pId_(pId)
    {
    }

  private:
    std::string                name_;
    [[maybe_unused]] unsigned *pId_{};
};

class ProductUniquePointer
{
  public:
    ProductUniquePointer() = default;
    explicit ProductUniquePointer(std::string name, unsigned Id)
        : name_(std::move(name)), pId_(std::make_unique<unsigned>(Id)) // make a copy
    {
    }

  private:
    std::string               name_;
    std::unique_ptr<unsigned> pId_;
};

class ProductSharedPointer
{
  public:
    ProductSharedPointer() = default;
    explicit ProductSharedPointer(std::string name, unsigned Id)
        : name_(name), pId_(std::make_shared<unsigned>(Id)) // make a copy
    {
    }

  private:
    std::string               name_;
    std::shared_ptr<unsigned> pId_;
};

int
main()
{
    ShowProps<Product>();
    ShowProps<ProductConst>();
    ShowProps<ProductRef>();
    ShowProps<ProductConstRef>();
    ShowProps<ProductRefWrapper>();
    ShowProps<ProductPointer>();
    ShowProps<ProductUniquePointer>();
    ShowProps<ProductSharedPointer>();

    // ProductConstRef pr;

    unsigned   id = 10;
    ProductRef p{"test", id};
    ProductRef p2{p};

    std::vector<Product> prods;
    prods.push_back(Product("box", 234));
    prods.push_back(Product("car", 567));
    // prods.insert(prods.begin(), Product("ball", 987));
}
