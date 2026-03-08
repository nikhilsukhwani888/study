#include "CUser2.hpp"
#include <iostream>

CUser2::CUser2()
{
}

void CUser2::Notify(std::string message)
{
    std::cout << "User2 received message: " << message << std::endl;
}