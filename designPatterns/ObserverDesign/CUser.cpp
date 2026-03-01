#include "CUser.hpp"

Cuser::Cuser(std::string name)
{
    username = name;
}

void Cuser::Notify(std::string message)
{
    std::cout << "Notification received by user: " << username << " with message: " << message << std::endl;
}