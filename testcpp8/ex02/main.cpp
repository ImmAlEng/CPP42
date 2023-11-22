#include "MutantStack.hpp"
#include <list>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    std::cout << "mstack top " << mstack.top() << std::endl;
    std::cout << std::endl;
    mstack.push(17);
    std::cout << "mstack top " << mstack.top() << std::endl;
    std::cout << std::endl;
    mstack.pop();
    std::cout << "mstack size: "<< mstack.size() << std::endl;
    std::cout << std::endl;
    mstack.push(3);
    std::cout << "mstack top " << mstack.top() << std::endl;
    std::cout << std::endl;
    mstack.push(5);
    std::cout << "mstack top " << mstack.top() << std::endl;
    std::cout << std::endl;
    mstack.push(737);
    std::cout << "mstack top " << mstack.top() << std::endl;
    std::cout << std::endl;
    mstack.push(0);
    MutantStack<int>::iterator mit = mstack.begin();
    MutantStack<int>::iterator mite = mstack.end();
    ++mit;
    --mit;
    while (mit != mite)
    {
        std::cout << *mit << std::endl;
        ++mit;
    }
    std::cout << "Mstack copy" << std::endl;
    MutantStack<int> test1(mstack);
    MutantStack<int>::iterator mitt = test1.begin();
    MutantStack<int>::iterator mitte = test1.end();
    ++mitt;
    --mitt;
    while (mitt != mitte)
    {
        std::cout << *mitt << std::endl;
        ++mitt;
    }
    std::cout << "Mstack copy assigned "<< std::endl;
    MutantStack<int> test2;
    test2 = mstack;
    MutantStack<int>::iterator mitt2 = test2.begin();
    MutantStack<int>::iterator mitte2 = test2.end();
    ++mitt2;
    --mitt2;
    while (mitt2 != mitte2)
    {
        std::cout << *mitt2 << std::endl;
        ++mitt2;
    }

    std::cout << std::endl;
    std::list<int> lstack;
    lstack.push_back(5);
    std::cout << "lstack top " << lstack.back() << std::endl;
    std::cout << std::endl;
    lstack.push_back(17);
    std::cout << "lstack top " << lstack.back() << std::endl;
    std::cout << std::endl;
    lstack.remove(17);
    std::cout << "lstack size: " << lstack.size() << std::endl;
    std::cout << std::endl;
    lstack.push_back(3);
    std::cout << "lstack top " << lstack.back() << std::endl;
    std::cout << std::endl;
    lstack.push_back(5);
    std::cout << "lstack top " << lstack.back() << std::endl;
    std::cout << std::endl;
    lstack.push_back(737);
    std::cout << "lstack top " << lstack.back() << std::endl;
    std::cout << std::endl;
    lstack.push_back(0);
    std::list<int>::iterator it = lstack.begin();
    std::list<int>::iterator ite = lstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    return (0);
}
