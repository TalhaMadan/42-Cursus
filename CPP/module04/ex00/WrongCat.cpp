#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << "WrongCat Default Constructor Called" << std::endl;
}

WrongCat::WrongCat(std::string type)
{
    this->type = type;
    std::cout << "WrongCat Constructor Called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy)
{
    *this = copy;
    std::cout << "WrongCat Copy Constructor Called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& copy)
{
    std::cout << "Copy Assignment Operator Called" << std::endl;
    if(this == &copy)
        return *this;
    this->type = copy.type;
    
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor Called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << " 🐾 fake Miav fake Miav 🐾 " << std::endl;
}


std::string WrongCat::getType() const
{
    return this->type;
}