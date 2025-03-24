#include <iostream>
#include <memory>
#include <vector>

class Shape
{
  public:
    virtual void
    render() const
    {
        std::cout << "rendering shape\n";
    }

    virtual ~Shape() = default;
};

class Circle : public Shape
{
  public:
    void
    render() const override
    {
        std::cout << "rendering circle\n";
    }

    virtual ~Circle() override = default;
};

class Rectangle : public Shape
{
  public:
    void
    render() const override
    {
        std::cout << "rendering rectangle\n";
    }

    virtual ~Rectangle() override = default;
};

int
main()
{
    using std::make_unique;
    using vec_shapes = std::vector<std::unique_ptr<Shape>>;

    // Unique pointers cannot be copied, they can only be moved, and passing
    // initializer_list doesn't give us any options to handle those cases.
    //
    // vec_shapes shapes{make_unique<Circle>(), make_unique<Rectangle>()};

    // The only way to build such a container is to use emplace_back or push_back:
    vec_shapes shapes;
    shapes.reserve(2);
    shapes.push_back(make_unique<Circle>());
    shapes.emplace_back(make_unique<Rectangle>());
}
