#include <vector>
#include <utility>  // std::pair
#include <iostream>

class CMinStack
{
    public:
    CMinStack();
    ~CMinStack();

    void push(int num);
    int getMin();
    int top();
    void pop();

    private:
    std::vector<std::pair<int, int>> st;
};