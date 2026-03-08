#include "CSingleton.hpp"

CSingleton* CSingleton::instance = nullptr; //The static member must be defined outside the class declaration.
std::mutex CSingleton::mtx; // Initialize the mutex

CSingleton::CSingleton()
{
    // Constructor can be empty or initialize other members
    std::cout << "Singleton instance created!" << std::endl;
}

CSingleton* CSingleton::getInstance()
{
    std::lock_guard<std::mutex> lock(mtx); // Lock the mutex to ensure thread safety
    if(instance == nullptr)
    {
        instance = new CSingleton();
    }
    return instance;
}