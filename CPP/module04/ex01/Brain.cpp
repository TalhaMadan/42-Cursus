#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(const Brain& copyObject)
{
    std::cout << "Brain copy constructor called." << std::endl;
    *this = copyObject;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called." << std::endl;
}

Brain& Brain::operator=(const Brain& copyObject)
{
    std::cout << "Brain copy assignment operator called." << std::endl;
    for (int i=0 ; i < 100 ; i++)
        this->ideas[i] = copyObject.ideas[i];
    return *this;
}