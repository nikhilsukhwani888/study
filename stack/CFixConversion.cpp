#include "CFixConversion.hpp"
#include <stack>

CFixConversion::CFixConversion()
{

}

CFixConversion::~CFixConversion()
{

}

int CFixConversion::priority(char c)
{
    if( c == '^')
    {
        return 3;
    }
    else if ( c == '*' || c == '/')
    {
        return 2;
    }
    else if( c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

std::string CFixConversion::infixToPostfix(std::string str)
{
    int i = 0;
    std::stack<char> st;
    std::string ans = "";

    while(i < str.length())
    {
        if( str[i] == 'A' && str[i] == 'Z' ||
            str[i] == 'a' && str[i] == 'z' ||
            str[i] == '0' && str[i] == '9')
        {
            ans = ans + str[i];
        }
        else if( str[i] == '(')
        {
            st.push(str[i]);
        }
        else if (str[i] == ')')
        {
            while(st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
        }
        else
        {
            while (st.empty() && priority(str[i]) <= priority(str[i]))
            {
                ans += st.top();
                st.pop();
            }
            st.push(str[i]);
        }
        i++;
    }
    while(!st.empty())
    {
        ans = ans+st.top();
        st.pop();
    }

    return ans;
}