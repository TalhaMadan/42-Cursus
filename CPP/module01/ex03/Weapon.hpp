#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class	Weapon
{
	private :
		std::string	type;
	public :
		Weapon();
		~Weapon();
		Weapon(std::string type) : type(type) {}
		const std::string& getType() const;
		void	setType(std::string intype);
};

#endif