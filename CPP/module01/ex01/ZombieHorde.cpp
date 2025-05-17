#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{	
	Zombie *army = new	Zombie[N];
	while (N > 0)
	{
		army[N].NameSetter(name);
		N--;
	}
	return (army);
}