#include "stack/CStack.hpp"
#include "stack/CFixConversion.hpp"
#include "stack/CMinStack.hpp"
#include "stack/CNextGreaterElement.hpp"
#include "multithreading/Example.hpp"

/**
 * 
 */

int main()
{
    std::cout << "Study Material" << std::endl;
  
    // std::vector<int> temp = {4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};
    // CNextGreaterElement *nge = new CNextGreaterElement();
    // nge->getNGE(temp);

    std::thread t1(Example::helloWorld, Example());

    t1.join();

    return 0;

}