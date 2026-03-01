#include "stack/CStack.hpp"
#include "stack/CFixConversion.hpp"
#include "stack/CMinStack.hpp"
#include "stack/CNextGreaterElement.hpp"
#include "multithreading/Example.hpp"
#include "multithreading/WeatherForecast.hpp"
#include "multithreading/CMutexExample.hpp"
#include "designPatterns/ObserverDesign/CChannel.hpp"
#include "designPatterns/ObserverDesign/CSubscribe.hpp"
#include "designPatterns/ObserverDesign/CUser.hpp"
#include "designPatterns/ObserverDesign/dummy.hpp"

/**
 * 
 */

int main()
{
    std::cout << "Study Material" << std::endl;
  
    // std::vector<int> temp = {4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};
    // CNextGreaterElement *nge = new CNextGreaterElement();
    // nge->getNGE(temp);
    
    // std::thread t1(CMutexExample::driveCar, CMutexExample(), "Driver 1");
    // std::thread t2(CMutexExample::driveCar, CMutexExample(), "Driver 2");

    // std::thread t3(CMutexExample::driveCarWithLockGuard, CMutexExample(), "Driver 3");
    // std::thread t4(CMutexExample::driveCarWithLockGuard, CMutexExample(), "Driver 4");

    // t1.join();
    // t2.join();
    // t3.join();
    // t4.join();

    CChannel channel;

    Cuser* subscriber1 = new Cuser("user1");
    Cuser* subscriber2 = new Cuser("user2");

    channel.subscribe(subscriber1);
    channel.subscribe(subscriber2);

    channel.notifySubscribers("Hello from channel!");

    dummy *dummySubscriber = new dummy();
    channel.subscribe(dummySubscriber);

    channel.notifySubscribers("Another message from channel!");

    channel.unsubscribe(subscriber1);

    channel.notifySubscribers("Message after unsubscribing subscriber1!");


    return 0;

}