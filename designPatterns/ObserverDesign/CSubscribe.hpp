#ifndef CSUBSCRIBE_HPP
#define CSUBSCRIBE_HPP

#include <string>

class CSubscribe
{
public:
    virtual void Notify(std::string message) = 0;
};

#endif // CSUBSCRIBE_HPP