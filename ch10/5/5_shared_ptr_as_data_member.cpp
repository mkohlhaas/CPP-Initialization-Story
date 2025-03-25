#include <iostream>
#include <memory>
#include <string>

// Using std::shared_ptr
//
// - It will be default constructible, but it’s best to assign some starting value to the pointer (or at least nullptr).
// - The compiler can generate a move constructor and move assignment operator.
// - Default copy operations are provided, but they are “shallow”.
//   This is still safer than copying raw pointers, as this time, we copy shared pointers which
//   increases their internal REFERENCE COUNTER, and thus the resource handling will be safe

struct Value
{
    explicit Value(int v) : v_(v)
    {
        std::cout << "Value(" << v_ << ")\n";
    }

    ~Value() noexcept
    {
        std::cout << "~Value(" << v_ << ")\n";
    }

    int v_;
};

class ProductWithSharedPtr
{
  private:
    std::string            name_;  //
    std::shared_ptr<Value> pId_{}; // shared pointer

  public:
    ProductWithSharedPtr() = default;

    explicit ProductWithSharedPtr(const char *name, std::shared_ptr<Value> pId) : name_(name), pId_(pId)
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
        return pId_ ? pId_->v_ : 0;
    }
};

int
main()
{
    auto pId = std::make_shared<Value>(123);                                      // Value(123)
    std::cout << "pId use count: " << pId.use_count() << '\n';                    // pId use count: 1

    ProductWithSharedPtr tvset{"TV Set", pId};                                    // makes a copy of shared pointer
    std::cout << "tvset: " << tvset.name() << ", id: " << tvset.id() << '\n';     // tvset: TV Set, id: 123
    std::cout << "pId use count: " << pId.use_count() << '\n';                    // pId use count: 2

    {
        ProductWithSharedPtr copy{tvset};                                         // another copy of shared pointer
        std::cout << "pId use count: " << pId.use_count() << '\n';                // pId use count: 3
        std::cout << "tvset: " << tvset.name() << ", id: " << tvset.id() << '\n'; // tvset: TV Set, id: 123
        std::cout << "copy:  " << copy.name() << ", id: " << copy.id() << '\n';   // copy:  TV Set, id: 123

        pId->v_ = 100;                                                            // reference to same Value
        std::cout << "tvset: " << tvset.name() << ", id: " << tvset.id() << '\n'; // tvset: TV Set, id: 100
        std::cout << "copy:  " << copy.name() << ", id: " << copy.id() << '\n';   // copy:  TV Set, id: 100
    }
    std::cout << "pId use count: " << pId.use_count() << '\n';                    // pId use count: 2
} // ~Value(100)
