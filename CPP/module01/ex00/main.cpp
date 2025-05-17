#include "Zombie.hpp"

Zombie*	newZombie(std::string name);

void	randomChump(std::string name);

int main()
{
	Zombie  *New = newZombie("Nwakame");
	New->announce();
	randomChump("Sörloth");
	delete New;
}