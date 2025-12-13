#include <string>
#include <iostream>

class CFixConversion
{
    public:
    CFixConversion();
    ~CFixConversion();

    std::string infixToPostfix(std::string str);

    private:
    int priority(char c);
};