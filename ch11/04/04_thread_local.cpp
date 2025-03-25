#include <iostream>
#include <mutex>
#include <thread>

std::mutex       mutPrint;
thread_local int x = 0;

void
foo()
{
    thread_local int y = 0;
    std::lock_guard  guard(mutPrint);
    std::cout << "in thread\t" << std::this_thread::get_id() << " ";
    std::cout << "&x " << &x << ", ";
    std::cout << "&y " << &y << '\n';
}

int
main()
{
    std::cout << "main     \t" << std::this_thread::get_id() << " &x " << &x << '\n';

    std::jthread worker1{foo}; // worker#1
    foo();                     // main thread
    std::jthread worker2{foo}; // worker#2
    foo();                     // main thread
}

// main         136757528606272 &x 0x7c6157e9b638
// in thread    136757528606272 &x 0x7c6157e9b638, &y 0x7c6157e9b63c
// in thread    136757528606272 &x 0x7c6157e9b638, &y 0x7c6157e9b63c
// in thread    136757523830464 &x 0x7c6157a0d6b8, &y 0x7c6157a0d6bc
// in thread    136757515437760 &x 0x7c615720c6b8, &y 0x7c615720c6bc
