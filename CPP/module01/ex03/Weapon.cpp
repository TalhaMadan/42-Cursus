#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::~Weapon() {}

const std::string&	Weapon::getType() const
{
	return this->type;
}

void	Weapon::setType(std::string intype)
{
	this->type = intype;
}