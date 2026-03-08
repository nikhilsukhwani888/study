#ifndef CSINGLETON_HPP
#define CSINGLETON_HPP

class CSingleton
{
private:
    CSingleton();
    static CSingleton* instance;

public:
    static CSingleton* getInstance();
};

#endif // CSINGLETON_HPP