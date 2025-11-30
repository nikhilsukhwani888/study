#include "CStack.hpp"

int main()
{
    CMyStack *obj = new CMyStack(10);
    obj->pop();
    obj->push(10);
    obj->printSt();
    obj->pop();
    obj->push(5);
    obj->printSt();

    std::cout << "stack: " << obj->isBalancedParanthesis("()()()(") << std::endl;
}