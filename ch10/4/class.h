#include <memory>

class MyClassImpl;

class MyClass
{
  private:
    std::unique_ptr<MyClassImpl> m_pImpl;

  public:
    MyClass();

    ~MyClass();

    // move
    MyClass(MyClass &&rhs) noexcept;
    MyClass &operator=(MyClass &&rhs) noexcept;

    // copy
    MyClass(const MyClass &rhs);
    MyClass &operator=(const MyClass &rhs);

    // API
    void DoSth();
    void DoConst() const;

  private:
    const MyClassImpl *
    Pimpl() const
    {
        // return m_pImpl.get();
        return m_pImpl.get();
    }

    MyClassImpl *
    Pimpl()
    {
        return m_pImpl.get();
    }
};
