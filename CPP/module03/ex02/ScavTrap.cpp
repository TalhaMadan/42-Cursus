#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap()
{
	this->name = "Default Cons";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "Default Constructor Called." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Default Destructor Called." << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "Constructor Called By " << name << " ." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy)
{
	*this = copy;
	std::cout << "Copy Constructor Called." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& object)
{
	if (this == &object)
		return *this;
	this->hitPoints = object.hitPoints;
	this->energyPoints = object.energyPoints;
	this->attackDamage = object.attackDamage;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
		std::cout << "ScavTrap "<< this->name << " attacks " << target << ", causing "<< this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
	else if (energyPoints == 0)
		std::cout << "Low Energy !" << std::endl;
	else
		std::cout << "ScavTrap " << this->name << " is died !" << std::endl;
}

void ScavTrap::guardGate(){
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}