#include <iostream>
#include <string>

// References as data members
//
// - Default constructor is problematic, as we cannot assign nullptr to a reference.
// - Default copy and move constructors are provided by the compiler, but they are
//   "shallow", like with a pointer.
// - Default copy and move assignment operators are DELETED, as the compiler cannot
//   implement them for a const data member.

class WrapperWithRef
{
  private:
    std::string &name_; // cannot set to "nullptr" or {} empty!

  public:
    // WrapperWithRef() = default; // cannot make it default...

    WrapperWithRef() = delete;

    explicit WrapperWithRef(std::string &n) : name_(n)
    {
    }

    const std::string &
    get_name() const
    {
        return name_;
    }

    void
    set_name(const std::string &name)
    {
        name_ = name;
    }
};

int
main()
{
    std::string str{"Name"};

    WrapperWithRef w{str};
    w.set_name(str);

    // copy constructor
    WrapperWithRef x{w};
    // references the same string
    std::cout << "str:      " << str << '\n';          // str:      Name
    std::cout << "x.name(): " << x.get_name() << '\n'; // x.name(): Name

    x.set_name("abc");
    std::cout << "str:      " << str << '\n';          // str:      abc
    std::cout << "x.name(): " << x.get_name() << '\n'; // x.name(): abc

    // WrapperWithRef def {};                          // cannot default construct
    // x = w;                                          // error, cannot assign
}
