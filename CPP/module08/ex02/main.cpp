#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    std::cout << "mstack values: " << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "top: " << s.top() << std::endl;
    std::cout << "size: " << s.size() << std::endl;

    std::cout << "\n-------LET'S DO MORE TESTS-------\n" << std::endl;

    MutantStack<int> boz(mstack);
    std::cout << "mstack's copy(boz) is created." << std::endl;
    for (int i = 0; i < 4; i++)
        boz.pop();
    std::cout << "size: " << boz.size() << std::endl;
    
    boz.push(1);
    boz.push(8);
    boz.push(3);
    boz.push(23);
    boz.push(28);

    std::cout << "\nNEW BOZ VALUES" << std::endl;

    MutantStack<int>::const_iterator i = boz.begin();
    MutantStack<int>::const_iterator i1 = boz.end();

    while (i != i1) {
        std::cout << *i << std::endl;
        ++i;
    }
    
    return 0;
}