#ifndef FRAPGTRAP_HPP
#define FRAPGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap:public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& copy);
		FragTrap& operator=(const FragTrap& copy);
		~FragTrap();

		void attack(const std::string& target);
		void highFivesGuys();
};

#endif