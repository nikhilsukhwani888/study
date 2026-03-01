
#include "CChannel.hpp"


CChannel::CChannel()
{
}

void CChannel::subscribe(CSubscribe* subscriber)
{
    subscribers.push_back(subscriber);
}

void CChannel::notifySubscribers(std::string message)
{
    for (auto subscriber : subscribers)
    {
        subscriber->Notify(message);
    }
}

void CChannel::unsubscribe(CSubscribe* subscriber)
{
    subscribers.erase(std::remove(subscribers.begin(), subscribers.end(), subscriber), subscribers.end());
}