#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class	Zombie
{
	private :
		std::string Name;
	public :
		Zombie();
		~Zombie();
		Zombie(std::string Name);
		void	announce(void);
		void	NameSetter(std::string name);
};

#endif
