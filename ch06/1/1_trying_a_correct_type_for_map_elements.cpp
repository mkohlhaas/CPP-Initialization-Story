#include <iostream>
#include <map>
#include <print>

// Auto Type Deduction Rules //

////////////////////////////////////////////////////////////////////////////////////////////
// 1. If the initializer is a constant expression, the type of the variable is deduced to //
//    be the type of the expression.                                                      //
////////////////////////////////////////////////////////////////////////////////////////////

auto num = 42;   // int
auto pi  = 3.14; // double

// special cases from string literal and nullptr:
auto str = "hello world"; // const char*
auto p   = nullptr;       // std::nullptr_t

/////////////////////////////////////////////////////////////////////////////////
// 2. If the initializer is an expression with a type that is not a reference, //
//    the type of the variable is deduced to be the type of the expression,    //
//    with TOP-LEVEL CV-QUALIFIERS REMOVED.                                    //
/////////////////////////////////////////////////////////////////////////////////

const int        cnum  = num;
const int       *pNum  = &num;
const int *const pCNum = &num;

// using direct initialization
auto a{num};    // int
auto a2{cnum};  // int         (const removed)
auto a3{pNum};  // const int * (doesn't have top-level const)
auto a4{pCNum}; // const int * (const removed)

// same deduction happens when you use copy initialization syntax
auto b  = num;   // int
auto b2 = cnum;  // int         (const removed)
auto b3 = pNum;  // const int * (doesn't have top-level const)
auto b4 = pCNum; // const int * (const removed)

/////////////////////////////////////////////////////////////////////////////////////////////
// 3. If the initializer is an expression with a type that is a reference, the type of the //
//    variable is deduced to be the type of the referred-to object, with                   //
//    TOP-LEVEL CV-QUALIFIERS AND REFERENCES REMOVED.                                      //
/////////////////////////////////////////////////////////////////////////////////////////////

int       &rnum  = num;
const int &crnum = num;

// direct initialization
auto c{num};    // int
auto c2{rnum};  // int (ref removed)
auto c3{crnum}; // int (const and ref removed)

// copy initialization syntax
auto d  = num;   // int
auto d2 = rnum;  // int (ref removed)
auto d3 = crnum; // int (const and ref removed)

//////////////////////////////////////////////////////////////////////////////////////////////
// 4. If the initializer is a braced-init-list, the type of the variable is deduced to be a //
//    std::initializer_list of the appropriate type.                                        //
//////////////////////////////////////////////////////////////////////////////////////////////

auto list = {1, 2, 3}; // std::initializer_list<int>
auto one  = {1.1};     // std::initializer_list<double>

//////////////////////////////////////////////////////////////////////////////////////////
// 5. If the initializer is a lambda expression, the type of the variable is deduced to //
//    be a unique, unnamed function type (we have to use auto).                         //
//////////////////////////////////////////////////////////////////////////////////////////

[[maybe_unused]] auto fooSquare = [](int x) { return x * x; };

////////////////////////////
// Adding type specifiers //
////////////////////////////

// You can also add a reference, const or a pointer signature to force concrete types
auto       &ref   = num;  // int &
const auto &cref  = num;  // const int &
auto       *pNum1 = &num; // int *

// auto&& is a universal reference/forward reference and
// can bind to lvalues and rvalues and preserves the constness.

std::string  hello{"Hello"};         // std::string
std::string &refHello = hello;       // std::string &

auto &&str1 = hello;                 // std::string &
auto &&rstr = refHello;              // std::string &

const std::string  world{"World"};   // const std::string
const std::string &refWorld = world; // const std::string &

auto &&w  = world;                   // const std::string &
auto &&rw = refWorld;                // const std::string &

// auto &str2 = std::string{"HI"};    // error: non-const lvalue cannot bind to rvalue!!!

const auto &str3 = std::string{"HI"}; // const std::string & (const lvalue can bind to rvalue!!!)
// str3[1]          = 'i';            // error, str3 is const

auto &&str4 = std::string{"HI"}; // std::string &&
// str4[1]          = 'i';            // OK!

int
main()
{
    using namespace std;

    map<string, int> m{
        {"hello", 1},
        {"world", 2},
    };

    // correct
    cout << m.begin()->first << ", " << addressof(m.begin()->first) << '\n';
    cout << next(m.begin())->first << ", " << addressof(next(m.begin())->first) << '\n';

    println();

    // OOPS!
    // string will be a copy
    // Map's key has to be declared constant!
    for (const pair<string, int> elem : m)
    {
        cout << elem.first << ", " << &elem.first << '\n';
    }

    println();

    // correct; uses original string
    for (const pair<const string, int> &elem : m)
    {
        cout << elem.first << ", " << &elem.first << '\n';
    }

    println();

    // correct
    for (const auto &elem : m)
    {
        cout << elem.first << ", " << &elem.first << '\n';
    }
}
