#include "Example.hpp"

Example::Example()
{
    std::cout << "Example Constructor called" << std::endl;
}

void Example::helloWorld()
{
    int num;
    std::cin >> num;
    std::cout << "you entered: " << num << std::endl;
}