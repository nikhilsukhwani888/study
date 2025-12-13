#include "CMinStack.hpp"

/**
 * L4. Implement Min Stack | Stack and Queue Playlist
 * https://www.youtube.com/watch?v=NdDIaH91P0g&list=PLgUwDviBIf0pOd5zvVVSzgpo6BaCpHT9c&index=4
 * 
 * Time Complexity - O(1)
 * Space Complexity - O(2xN) -> pair of num
 * 
 * Example -> 
 *  CMinStack *obj3 = new CMinStack();
    obj3->push(12);
    obj3->push(15);
    obj3->push(10);
    std::cout << "getMin: " << obj3->getMin() << std::endl;
    obj3->pop();
    std::cout << "top: " << obj3->top() << std::endl;
    std::cout << "getMin: " << obj3->getMin() << std::endl;

 * Output ->
 *  element push: 12 with current min: 12
    Element's in stack: (12, 12),
    element push: 15 with current min: 12
    Element's in stack: (12, 12), (15, 12),
    element push: 10 with current min: 10
    Element's in stack: (12, 12), (15, 12), (10, 10),
    getMin: 10
    top: 15
    getMin: 12
 
 */


CMinStack::CMinStack()
{

}

CMinStack::~CMinStack()
{

}

void CMinStack::push(int num)
{
    int min = (st.empty()) ? num : (getMin() > num) ? num : getMin();
    st.push_back({num, min});

    std::cout << "element push: " << num << " with current min: " << min << std::endl;
    std::cout << "Element's in stack: ";
    for (std::pair a : st)
    {
        std::cout << "(" << a.first << ", " << a.second << "), ";
    }
    std::cout << std::endl;
}

int CMinStack::getMin()
{
    return st[st.size()-1].second;
}

int CMinStack::top()
{
    return st[st.size()-1].first;
}

void CMinStack::pop()
{
    st.pop_back();   
}
