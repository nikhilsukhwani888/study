#include "CSingleton.hpp"

CSingleton* CSingleton::instance = nullptr; //The static member must be defined outside the class declaration.

CSingleton::CSingleton()
{
    // Constructor can be empty or initialize other members
}

CSingleton* CSingleton::getInstance()
{
    if(instance == nullptr)
    {
        instance = new CSingleton();
    }
    return instance;
}