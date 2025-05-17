#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout   <<  "Zombie \"" << "<NULL>" << "\" was born with default constructor." << std::endl;
}

Zombie::~Zombie()
{
	std::cout   <<  "Zombie \"" << Name << "\" is destroyed." << std::endl;
}

Zombie::Zombie(std::string Name) : Name(Name)
{
	std::cout   <<  "Zombie \"" << Name << "\" was born." << std::endl;
}

void	Zombie::NameSetter(std::string name)
{
	this->Name = name;
}

void    Zombie::announce()
{
	std::cout << Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
