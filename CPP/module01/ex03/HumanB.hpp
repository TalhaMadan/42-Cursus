#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private :
		std::string name;
		Weapon *weapon;
	public :
		HumanB();
		~HumanB();
		HumanB(const std::string& name) : name(name){}
		void	attack();
        void    setWeapon(Weapon *newWeapon);
        std::string getName();
		
};

#endif