#include "class.h"
#include <iostream>

class MyClassImpl
{
  public:
    void
    DoStuff()
    {
        std::cout << "I am doing stuff ..." << std::endl;
    }
};

MyClass::MyClass() : pImpl_(new MyClassImpl())
{
}

MyClass::~MyClass()
{
    delete pImpl_;
}

void
MyClass::DoSth()
{
    pImpl_->DoStuff();
}
