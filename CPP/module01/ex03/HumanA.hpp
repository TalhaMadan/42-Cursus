#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private :
		std::string name;
		Weapon *weapon;
	public :
		HumanA();
		~HumanA();
		HumanA(std::string name, Weapon *weapon);
		void setWeapon(Weapon *inWeapon);
		void setName(std::string inname);
		std::string	getName();
		void	attack();
};

#endif