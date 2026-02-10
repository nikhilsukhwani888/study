#include "CMutexExample.hpp"

std::mutex mtx; // mutex for critical section

/**main.cpp ->
 * 
 * 
 * std::thread t1(CMutexExample::driveCar, CMutexExample(), "Driver 1");
    std::thread t2(CMutexExample::driveCar, CMutexExample(), "Driver 2");

    std::thread t3(CMutexExample::driveCarWithLockGuard, CMutexExample(), "Driver 3");
    std::thread t4(CMutexExample::driveCarWithLockGuard, CMutexExample(), "Driver 4");

    t1.join();
    t2.join();
    t3.join();
    t4.join();
 */

CMutexExample::CMutexExample()
{
    std::cout << "CMutexExample Constructor called" << std::endl;
}

void CMutexExample::driveCar(std::string driverName)
{
    std::unique_lock<std::mutex> lock(mtx); // lock the mutex for this scope
    std::cout << "UniqueLock: " << driverName << " is driving" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "UniqueLock: " << driverName << " has stopped driving" << std::endl;
    lock.unlock(); // unlock the mutex
}

void CMutexExample::driveCarWithLockGuard(std::string driverName)
{
    std::lock_guard<std::mutex> lock(mtx); // lock the mutex for this scope
    std::cout << "LockGuard: " << driverName << " is driving" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "LockGuard: " << driverName << " has stopped driving" << std::endl;
    // lock is automatically released when it goes out of scope
}