#include <iostream>
#include <stdexcept>

constexpr int LOWEST_ID_VALUE = -100;

class Product
{
  public:
    Product(int id, const std::string &name) : m_id{id}, m_name{name}
    {
        std::cout << "Product: " << m_id << ", " << m_name << '\n';
        if (m_id < LOWEST_ID_VALUE)
        {
            throw std::invalid_argument{"id cannot be lower than LOWEST_ID_VALUE!"};
        }
    }

    std::string
    Name() const
    {
        return m_name;
    }

  private:
    int         m_id;
    std::string m_name;
};

int
main()
{
    try
    {
        Product car(10, "car");
        std::cout << car.Name() << " created\n";

        Product box(-101, "box");
        std::cout << box.Name() << " created\n";
    }
    catch (const std::exception &ex)
    {
        std::cout << "Error - " << ex.what() << '\n';
    }
}
