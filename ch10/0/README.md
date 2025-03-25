PIMPL Idiom

We declare a pointer to some incomplete type in the header file.

A pointer has a well-defined size (usually 4 or 8 bytes), so the compiler can adequately evaluate the size of
the MyClass class, even though it points to some incomplete MyClassImpl.

Inside the cpp file, we declare and define the implementation class.

PIMPL is often used to reduce compilation times, and in C++20, this might NOT BE NEEDED BECAUSE OF MODULES.
Still, PIMPL can be handy when you want to hide the implementation details and protect against ABI changes completely.
