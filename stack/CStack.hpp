#include "stdint.h"
#include <iostream>
#include "vector"
#include <string>

class CMyStack
{
public:
    CMyStack(int size);
    ~CMyStack();

    void push(int num);
    int pop();
    int top();
    int size();
    void printSt();
    bool isBalancedParanthesis(std::string sr);

private:
    int mSize;
    std::vector<int> arr;
    int mTop;
};