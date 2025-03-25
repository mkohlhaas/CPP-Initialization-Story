class MyClassImpl;

class MyClass
{
  public:
    MyClass();
    ~MyClass();

    void DoSth();

  private:
    MyClassImpl *pImpl_{};
};
