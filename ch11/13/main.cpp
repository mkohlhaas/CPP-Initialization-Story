#include "test.h"
#include <iostream>

void foo();

static Value local{100};

int
main()
{
    std::cout << "Main starting...\n";
    foo();
    Test t;
    std::cout << local.v << '\n';
    local.v += 1;
    std::cout << local.v << '\n';
}

// Value(42)
// Value(24)
// Value(100)
// Value(300)
// Value(200)
// Main starting...
// foo starting...
// Test::Test()
// 200
// Test::~Test()
// Test::Test()
// 100
// 101
// Test::~Test()
// ~Value(200)
// ~Value(300)
// ~Value(100)
// ~Value(24)
// ~Value(42)
