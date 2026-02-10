#include "CStack.hpp"
#include "CFixConversion.hpp"

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

    CFixConversion *obj2 = new CFixConversion();
    std::cout << "Infix to postfix: " << obj2->infixToPostfix("a+b*(c^d-e)") << std::endl;
}