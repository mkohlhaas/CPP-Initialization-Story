#include <string>

// global vars can be initialized inline (not outline in a separate cpp implementtion file)
// inline keyword actually not needed

constexpr int gMyGlobal{10};

const std::string gHelloText{"Hello World "};

namespace appConstants
{
    constexpr double  scalingFactor{1.33};
    const std::string appName{"Testing app"};
} // namespace appConstants
