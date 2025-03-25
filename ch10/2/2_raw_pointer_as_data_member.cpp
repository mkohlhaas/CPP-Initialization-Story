#include <iostream>
#include <string>

// Pointers as data members
//
// - It will be default constructible, but it’s best to assign some starting value to the pointer
//   (or at least nullptr).
// - The compiler can generate a copy and move constructors, but it will be a shallow copy!
// - The compiler can create default copy assignment and move assignment operators, but
//   the operations will also be shallow!

// Warning: "don't use raw pointers"

class DangerousWrapper
{
  private:
    std::string *pName_{nullptr}; // raw pointer as data member

  public:
    explicit DangerousWrapper(std::string *pstr) : pName_(pstr)
    {
    }

    std::string *
    name() const
    {
        return pName_;
    }

    void
    name(std::string *pstr)
    {
        pName_ = pstr;
    }
};

DangerousWrapper
foo()
{
    std::string      str{"Another Name"}; //
    DangerousWrapper w{&str};
    return w;                             // oops: str is destructed and the pointer in w points to garbage!!!
}

int
main()
{
    std::string      str{"Name"};
    DangerousWrapper w{&str};

    // x and w are pointing at the same string
    DangerousWrapper x{w};
    std::cout << *w.name() << '\n'; // Name
    std::cout << *x.name() << '\n'; // Name

    std::cout << std::endl;

    *(x.name()) = "Other";
    std::cout << *w.name() << '\n'; // Other
    std::cout << *x.name() << '\n'; // Other

    auto y = foo();                 // oops... !!
    std::cout << *y.name() << '\n';
}
