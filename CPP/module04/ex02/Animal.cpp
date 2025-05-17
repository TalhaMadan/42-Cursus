#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal default constructor called." << std::endl;
    this->type = "unknown";
}

Animal::Animal(const std::string& type)
{
    std::cout << "Animal constructor for " << type << "  called." << std::endl;
    this->type = type;
}

Animal::Animal(const Animal& copyObject)
{
    std::cout << "Animal copy constructor called." << std::endl;
    *this = copyObject;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called." << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}

Animal& Animal::operator=(const Animal& copyObject)
{
    std::cout << "Assignment operator called." << std::endl;
    this->type = copyObject.getType();
    return *this;
}
