#ifndef CSINGLETON_HPP
#define CSINGLETON_HPP

#include <iostream>
#include <mutex>

class CSingleton
{
private:
    CSingleton();

    static std::mutex mtx; // Mutex for thread safety (if needed)
    static CSingleton* instance;

public:
    static CSingleton* getInstance();
};

#endif // CSINGLETON_HPP