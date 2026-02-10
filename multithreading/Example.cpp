#include "Example.hpp"


/** Main.cpp ->
 * 
 * std::thread t1(Example::helloWorld, Example(), '*');
    std::thread t2(Example::helloWorld2, Example());

    t1.join();
    t2.join();
 */

Example::Example()
{
    std::cout << "Example Constructor called" << std::endl;
}

void Example::helloWorld(char symbol)
{
    for(int i = 0; i < 100; i++)
    {
        std::cout << symbol;
    }
}

void Example::helloWorld2()
{
    for(int i = 0; i < 100; i++)
    {
        std::cout << "-" ;
    }
}