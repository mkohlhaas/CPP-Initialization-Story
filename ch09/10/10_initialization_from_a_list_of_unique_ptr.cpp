
#include <iostream>
#include <memory>
#include <vector>

struct Shape
{
    virtual void
    render() const
    {
        std::cout << "rendering shape\n";
    }
};

struct Circle : Shape
{
    void
    render() const override
    {
        std::cout << "rendering circle\n";
    }
};

struct Rectangle : Shape
{
    void
    render() const override
    {
        std::cout << "rendering rectangle\n";
    }
};

template <typename T, typename... Args>
auto
initFromMoveable(Args &&...args)
{
    std::vector<std::unique_ptr<T>> vec;
    vec.reserve(sizeof...(Args));
    (vec.emplace_back(std::forward<Args>(args)), ...);
    return vec;
}

int
main()
{
    /* does not work:
    std::vector<std::unique_ptr<Shape>> shapes {
        std::make_unique<Circle>(),
        std::make_unique<Rectangle>()
    };
    */

    auto shapes = initFromMoveable<Shape>(std::make_unique<Circle>(), std::make_unique<Rectangle>());
}
