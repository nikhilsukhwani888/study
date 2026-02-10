#include "CStack.hpp"
#include <stack>

using namespace std;

CMyStack::CMyStack(int size) : mSize(size), mTop(-1), arr{size}
{
}

CMyStack::~CMyStack()
{
}

void CMyStack::push(int num)
{
    mTop += 1;
    cout << "mTop " << mTop << ", size " << arr.size() <<endl;
    arr[mTop] = num;
}

int CMyStack::pop()
{
    cout << "pop" << endl;
    if (mTop == -1)
    {
        cout << "no element available" << endl;
        return -1;
    }
    else
    {
        if (mTop == 0)
        {
            mTop = -1;
            return 0;
        }
        else
        {
            mTop--;
            return static_cast<int>(arr[mTop]);
        }
    }
}

int CMyStack::top()
{
    return arr[mTop];
}

int CMyStack::size()
{
    return static_cast<int>(arr.size());
}

void CMyStack::printSt()
{
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}

bool CMyStack::isBalancedParanthesis(std::string str)
{
    stack<char> s;

    int idx = 0;
    for( char c: str)
    {
        if (c == ')')
        {
            if (s.top() != '(')
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
        else if (c == ']')
        {
            if (s.top() != '[')
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
        else if (c == '}')
        {
            if (s.top() != '{')
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
        else
        {
            s.push(c);
        }
    }
    return s.empty();

}