#pragma once

#include <iostream>

struct Value
{
    Value(int x) : v(x)
    {
        std::cout << "Value(" << v << ")\n";
    }

    ~Value() noexcept
    {
        std::cout << "~Value(" << v << ")\n";
    }

    int v{0};
};

struct Test
{
    Test()
    {
        puts("Test::Test()");
    }

    ~Test() noexcept
    {
        puts("Test::~Test()");
    }

    static inline Value u{42}; // inline allow us to initialize static var in header
    static inline Value v{24};
};
