#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
	int	N = 15;
	Zombie *army = zombieHorde(N, "TM");
	while (N > 0)
	{
		army[N].announce();
		N--;
	}
	delete [] army;
}