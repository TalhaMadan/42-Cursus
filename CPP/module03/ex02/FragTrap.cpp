#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->name = "Default Cons";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "Default Constructor Called." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "Default Destructor Called." << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "Constructor Called By " << name << " ." << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy)
{
	*this = copy;
	std::cout << "Copy Constructor Called." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& object)
{
	if (this == &object)
		return *this;
	this->hitPoints = object.hitPoints;
	this->energyPoints = object.energyPoints;
	this->attackDamage = object.attackDamage;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

void	FragTrap::attack(const std::string &target)
{
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
		std::cout << "FragTrap "<< this->name << " attacks " << target << ", causing "<< this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
	else if (energyPoints == 0)
		std::cout << "Low Energy !" << std::endl;
	else
		std::cout << "FragTrap " << this->name << " is died !" << std::endl;
}

void FragTrap::highFivesGuys(){
	std::cout << "👋🏻 Hey guys how about a high five? 👋🏻" << std::endl;
}