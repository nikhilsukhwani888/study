#include <vector>
#include <iostream>

class CNextGreaterElement
{
    public:
    CNextGreaterElement();
    ~CNextGreaterElement();

    std::vector<int> getNGE(std::vector<int> arr);
    int top();

    private:
    std::vector<int> st;
};