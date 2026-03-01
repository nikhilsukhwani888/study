#include "CSubscribe.hpp"
#include <iostream>

class Cuser : public CSubscribe
{
    std::string username;
public:
    Cuser(std::string name);
    void Notify(std::string message) override;
};