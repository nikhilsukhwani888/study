#ifndef CCHANNEL_HPP
#define CCHANNEL_HPP

#include "CSubscribe.hpp"
#include <vector>
#include <algorithm>

class CChannel
{
public:
    CChannel();
    void subscribe(CSubscribe* subscriber);
    void notifySubscribers(std::string message);
    void unsubscribe(CSubscribe* subscriber);
    
    std::vector<CSubscribe*> subscribers;
};


#endif // CCHANNEL_HPP