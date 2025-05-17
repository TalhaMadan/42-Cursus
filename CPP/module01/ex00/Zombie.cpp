#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie()
{
	std::cout   <<  "Zombie \"" << Name << "\" is destroyed." << std::endl;
}

Zombie::Zombie(std::string Name) : Name(Name)
{
	std::cout   <<  "Zombie \"" << Name << "\" was born." << std::endl;
}

void    Zombie::announce()
{
	std::cout << Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
