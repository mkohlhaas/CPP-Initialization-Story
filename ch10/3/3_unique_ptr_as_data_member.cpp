#include <iostream>
#include <memory>
#include <string>

// Smart pointers as data members

// Only move constructor and move assignment are defaulted,
// but not copy operations.

class Value
{
  public:
    explicit Value(int v) : v_(v)
    {
        std::cout << "Value(" << v_ << ")\n";
    }

    ~Value() noexcept
    {
        std::cout << "~Value(" << v_ << ")\n";
    }

    int
    get_v()
    {
        return v_;
    }

  private:
    int v_;
};

class ProductUniquePointer
{
  private:
    std::string            name_;
    std::unique_ptr<Value> pId_; // smart pointer

  public:
    ProductUniquePointer() = default;

    explicit ProductUniquePointer(const char *name, std::unique_ptr<Value> pId) : name_(name), pId_(std::move(pId))
    {
    }

    const std::string &
    name() const
    {
        return name_;
    }

    int
    id() const
    {
        return pId_ ? pId_->get_v() : 0;
    }
};

int
main()
{
    auto pId = std::make_unique<Value>(123);                                  // Value(123)

    ProductUniquePointer tvset{"TV Set", std::move(pId)};
    std::cout << "tvset: " << tvset.name() << ", id: " << tvset.id() << '\n'; // tvset: TV Set, id: 123

    // move constructor (default created)
    ProductUniquePointer moved{std::move(tvset)};
    std::cout << "tvset: " << tvset.name() << ", id: " << tvset.id() << '\n';  // tvset: , id: 0
    std::cout << "moved:  " << moved.name() << ", id: " << moved.id() << '\n'; // moved:  TV Set, id: 123

    // copy assignment operator (not default created)
    //
    // error: Object of type 'ProductUniquePointer' cannot be assigned
    // because its copy assignment operator is implicitly deleted:
    // tvset = moved;
} // ~Value(123)
