#include "CNextGreaterElement.hpp"

/**
 * L5. Next Greater Element | Stack and Queue Playlist
 * https://www.youtube.com/watch?v=e7XQLtOQM3I&list=PLgUwDviBIf0pOd5zvVVSzgpo6BaCpHT9c&index=5
 * 
 * Example ->
 * std::vector<int> temp = {4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};
    CNextGreaterElement *nge = new CNextGreaterElement();
 *
 * Output -> 
 * stack-  6
    nge- stack-  0 0 0 0 0 0 0 0 0 0 0 -1
    stack-  6 4
    nge- stack-  0 0 0 0 0 0 0 0 0 0 6 -1
    stack-  6 4 2
    nge- stack-  0 0 0 0 0 0 0 0 0 4 6 -1
    stack-  6 4 2 1
    nge- stack-  0 0 0 0 0 0 0 0 2 4 6 -1
    stack-  6 4 3
    nge- stack-  0 0 0 0 0 0 0 4 2 4 6 -1
    stack-  6 5
    nge- stack-  0 0 0 0 0 0 6 4 2 4 6 -1
    stack-  6 5 2
    nge- stack-  0 0 0 0 0 5 6 4 2 4 6 -1
    stack-  6 5 2 1
    nge- stack-  0 0 0 0 2 5 6 4 2 4 6 -1
    stack-  6 5 3
    nge- stack-  0 0 0 5 2 5 6 4 2 4 6 -1
    stack-  6 5
    nge- stack-  0 0 6 5 2 5 6 4 2 4 6 -1
    stack-  12
    nge- stack-  0 -1 6 5 2 5 6 4 2 4 6 -1
    stack-  12 4
    nge- stack-  12 -1 6 5 2 5 6 4 2 4 6 -1
 * 

 *
 *
 * Time Complexity -> O(2N)
 * Space Complexity -> O(N) +  O(N) (stack+NGE)
 */


CNextGreaterElement::CNextGreaterElement()
{
    
}

CNextGreaterElement::~CNextGreaterElement()
{
    
}

//  [4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6]
std::vector<int> CNextGreaterElement::getNGE(std::vector<int> arr)
{
    std::vector<int> nge(arr.size());
    for( int i = arr.size()-1; i >= 0; --i)
    {
        if(st.empty())
        {
            nge[i] = -1;
            st.push_back(arr[i]);
        }
        else if( top() > arr[i])
        {
            nge[i] = top();
            st.push_back(arr[i]);
        }
        else
        {
            while(!st.empty() && top() <= arr[i])
            {
                st.pop_back();
            }
            if(st.empty())
            {
                nge[i] = -1;
                st.push_back(arr[i]);
            }
            else
            {
                nge[i] = top();
                st.push_back(arr[i]);
            }
        }

        std::cout << "stack- ";
        for(int a: st)
        {
            std::cout << " " << a;
        }

        std::cout << std::endl << "nge- ";
        std::cout << "stack- ";
        for(int a: nge)
        {
            std::cout << " " << a;
        }
        std::cout << std::endl;
    }
    return nge;
}

int CNextGreaterElement::top()
{
    return st[st.size()-1];
}