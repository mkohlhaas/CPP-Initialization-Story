#include <iostream>

struct SimpleType
{
    int field{1};
};

int
main()
{
    SimpleType st;
    std::cout << "st.field = " << st.field << '\n';
}
