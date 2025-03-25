#include "class.h"

int
main()
{
    auto my = MyClass{};

    my.DoSth();   // MyClass::DoSth() wrapper
                  // Impl::DoSth()
    my.DoConst(); // MyClass::DoConst() wrapper
                  // Impl::DoConst()
}
