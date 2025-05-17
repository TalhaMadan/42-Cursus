#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB() {}

HumanB::~HumanB() {}

std::string HumanB::getName()
{
	return this->name;
}

void    HumanB::setWeapon(Weapon *newWeapon)
{
	this->weapon = newWeapon;
}

void    HumanB::attack()
{
	std::cout << getName() << " attacks with their " << weapon->getType() << std::endl;
}