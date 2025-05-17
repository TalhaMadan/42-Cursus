#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default constructor called." << std::endl;
    try
    {
        this->brain = new Brain();
    }
    catch (const std::bad_alloc& e)
    {
        std::cerr << "Allocation error! " << e.what() << '\n';
        throw;
    }
}

Cat::Cat(const Cat& copyObject) : Animal(copyObject)
{
    std::cout << "Cat copy constructor called." << std::endl;
    this->brain = NULL;
    *this = copyObject;
}

Cat::~Cat()
{
    delete(this->brain);
    std::cout << "Cat destructor called." << std::endl;
}

Brain* Cat::getBrain() const
{
    return this->brain;
}

void Cat::makeSound() const
{
    std::cout << "Meow <3" << std::endl;
}

Cat& Cat::operator=(const Cat& copyObject)
{
    std::cout << "Cat assignment operator called." << std::endl;
    if (this->brain != NULL)
        delete(this->brain);
    try
    {
        this->brain = new Brain();
        *this->brain = *copyObject.getBrain(); 
    } 
    catch (std::bad_alloc& e)
    {
        std::cout << "Allocation error!" << e.what() << std::endl;
        exit(1);
    }
    return *this;
}
