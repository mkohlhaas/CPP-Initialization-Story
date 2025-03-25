#include "class.h"
#include <iostream>

class MyClassImpl
{
  public:
    void
    DoSth()
    {
        std::cout << "Impl::DoSth()\n";
    }

    void
    DoConst() const
    {
        std::cout << "Impl::DoConst()\n";
    }
};

MyClass::MyClass() : m_pImpl(std::make_unique<MyClassImpl>())
{
}

MyClass::~MyClass() = default;

// move
MyClass::MyClass(MyClass &&) noexcept            = default;
MyClass &MyClass::operator=(MyClass &&) noexcept = default;

// copy
MyClass::MyClass(const MyClass &rhs) : m_pImpl(std::make_unique<MyClassImpl>(*rhs.m_pImpl))
{
}

// copy
MyClass &
MyClass::operator=(const MyClass &rhs)
{
    if (this != &rhs)
    {
        m_pImpl = std::make_unique<MyClassImpl>(*rhs.m_pImpl);
    }
    return *this;
}

// API
void
MyClass::DoSth()
{
    std::cout << "MyClass::DoSth() wrapper\n";
    Pimpl()->DoSth();
}

void
MyClass::DoConst() const
{
    std::cout << "MyClass::DoConst() wrapper\n";
    Pimpl()->DoConst();
};
