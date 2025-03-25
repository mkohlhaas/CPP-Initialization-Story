#include <iostream>
#include <string>

// Changing to std::reference_wrapper

// std::reference_wrapper wraps a reference in a copyable, assignable object.

class WrapperWitStdhRef
{
  private:
    std::reference_wrapper<std::string> name_;

  public:
    // WrapperWitStdhRef() = default; // cannot make it default...

    WrapperWitStdhRef() = delete;

    explicit WrapperWitStdhRef(std::string &n) : name_(n)
    {
    }

    const std::string &
    get_name() const
    {
        return name_;
    }

    void
    rebind(std::string &name)
    {
        name_ = name;                 // regular assignment operator rebinds the reference
    }

    void
    set_name(const std::string &name) //
    {
        name_.get() = name;           // to change the pointer you need to use the .get() member function
    }
};

int
main()
{
    std::string str{"Name"};

    // WrapperWitStdhRef def {}; // cannot default construct

    WrapperWitStdhRef w{str};
    w.set_name(str);

    WrapperWitStdhRef x{w};
    std::cout << "str:      " << str << '\n';          // str:      Name
    std::cout << "x.name(): " << x.get_name() << '\n'; // x.name(): Name
    std::cout << "w.name(): " << w.get_name() << '\n'; // w.name(): Name

    std::cout << std::endl;

    x.set_name("abc");
    std::cout << "str:      " << str << '\n';          // str:      abc
    std::cout << "x.name(): " << x.get_name() << '\n'; // x.name(): abc
    std::cout << "w.name(): " << w.get_name() << '\n'; // w.name(): abc

    std::cout << std::endl;

    x.set_name("cba");
    x = w;                                             // OK
    std::cout << "str:      " << str << '\n';          // str:      cba
    std::cout << "x.name(): " << x.get_name() << '\n'; // x.name(): cba
    std::cout << "w.name(): " << w.get_name() << '\n'; // w.name(): cba

    std::cout << std::endl;

    std::string str1{"xyz"};
    x.rebind(str1);
    std::cout << "str:      " << str << '\n';          // str:      cba
    std::cout << "x.name(): " << x.get_name() << '\n'; // x.name(): xyz
    std::cout << "w.name(): " << w.get_name() << '\n'; // w.name(): cba
}
