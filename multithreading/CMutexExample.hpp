#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

class CMutexExample
{
    public:
    CMutexExample();
    void driveCar(std::string driverName);
    void driveCarWithLockGuard(std::string driverName);
};