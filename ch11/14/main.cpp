#include "counted_type.h"
#include <iostream>

int
main()
{
    {
        CountedType c0;
        CountedType c1;
        std::cout << CountedType::classCounter << '\n'; // 2
    }

    std::cout << CountedType::classCounter << '\n';     // 0
}
