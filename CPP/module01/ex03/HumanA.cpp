#include "Weapon.hpp"
#include "HumanA.hpp"
#include <string>

HumanA::HumanA() {}

HumanA::~HumanA() {}

HumanA::HumanA(const std::string name, Weapon *weapon)
{
	setName(name);
	setWeapon(weapon);
}

void	HumanA::setName(std::string inname)
{
	this->name = inname;
}

std::string	HumanA::getName()
{
	return this->name;
}

void HumanA::setWeapon(Weapon *inWeapon)
{
    this->weapon = inWeapon;
}

void	HumanA::attack()
{
	std::cout << getName() << " attacks with their " << weapon->getType() << std::endl;
}