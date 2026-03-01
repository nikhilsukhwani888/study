#include "dummy.hpp"
#include <iostream>

dummy::dummy()
{
}

void dummy::Notify(std::string message)
{
    std::cout << "Dummy received message: " << message << std::endl;
}