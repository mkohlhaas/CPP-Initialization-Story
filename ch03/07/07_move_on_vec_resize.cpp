#include <print>
#include <string>
#include <vector>

class Product
{
  public:
    Product(int id, const std::string &name) : id_{id}, name_{name}
    {
        std::println("Product():     {}, {}", id_, name_);
    }

    Product(const Product &other) : id_{other.id_}, name_{other.name_}
    {
        std::println("Product(copy): {}, {}", id_, name_);
    }

    Product(Product &&other) noexcept : id_{other.id_}, name_{std::move(other.name_)}
    {
        std::println("Product(move): {}, {}", id_, name_);
    }

    std::string
    Name() const
    {
        return name_;
    }

  private:
    int         id_;
    std::string name_;
};

int
main()
{
    std::vector<Product> prods;
    std::println("{}, {}", prods.size(), prods.capacity());

    prods.emplace_back(101, "car");
    std::println("{}, {}", prods.size(), prods.capacity());
    prods.emplace_back(202, "box");
    std::println("{}, {}", prods.size(), prods.capacity());
    prods.emplace_back(303, "toy");
    std::println("{}, {}", prods.size(), prods.capacity());
    prods.emplace_back(404, "mug");
    std::println("{}, {}", prods.size(), prods.capacity());
    prods.emplace_back(505, "pencil");
    std::println("{}, {}", prods.size(), prods.capacity());
    prods.emplace_back(606, "pencil");
    std::println("{}, {}", prods.size(), prods.capacity());
    prods.emplace_back(707, "pencil");
    std::println("{}, {}", prods.size(), prods.capacity());
    prods.emplace_back(808, "pencil");
    std::println("{}, {}", prods.size(), prods.capacity());
    prods.emplace_back(909, "pencil");
    std::println("{}, {}", prods.size(), prods.capacity());
}

// 0, 0
// Product():     101, car
// 1, 1
// Product():     202, box
// Product(move): 101, car
// 2, 2
// Product():     303, toy
// Product(move): 101, car
// Product(move): 202, box
// 3, 4
// Product():     404, mug
// 4, 4
// Product():     505, pencil
// Product(move): 101, car
// Product(move): 202, box
// Product(move): 303, toy
// Product(move): 404, mug
// 5, 8
// Product():     606, pencil
// 6, 8
// Product():     707, pencil
// 7, 8
// Product():     808, pencil
// 8, 8
// Product():     909, pencil
// Product(move): 101, car
// Product(move): 202, box
// Product(move): 303, toy
// Product(move): 404, mug
// Product(move): 505, pencil
// Product(move): 606, pencil
// Product(move): 707, pencil
// Product(move): 808, pencil
// 9, 16
