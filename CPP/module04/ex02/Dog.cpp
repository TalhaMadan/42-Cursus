#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog default constructor called." << std::endl;
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

Dog::Dog(const Dog& copyObject) : Animal(copyObject)
{
    std::cout << "Dog copy constructor called." << std::endl;
    this->brain = NULL;
    *this = copyObject;
}

Dog::~Dog()
{
    delete(this->brain);
    std::cout << "Dog destructor called." << std::endl;
}

Brain* Dog::getBrain() const
{
    return this->brain;
}

void Dog::makeSound() const
{
    std::cout << "Bark!" << std::endl;
}

Dog& Dog::operator=(const Dog& copyObject)
{
    std::cout << "Dog copy assignment operator called." << std::endl;
    if (this->brain != NULL)
        delete(this->brain);
    try
    {
        this->brain = new Brain();
        *this->brain = *copyObject.getBrain(); 
    } 
    catch (std::bad_alloc& e)
    {
        std::cout << "Allocation error !" << e.what() << std::endl;
        exit(1);
    }
    return *this;
}