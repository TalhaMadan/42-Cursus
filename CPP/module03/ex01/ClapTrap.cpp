#include "ClapTrap.hpp"
#include <string>

ClapTrap::ClapTrap()
{
	this->name = "Default Cons";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "Default Constructor Called." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Default Destructor Called." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "Constructor Called By " << name << " ." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	*this = copy;
	std::cout << "Copy Constructor Called." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& object)
{
	if (this == &object)
		return *this;
	this->hitPoints = object.hitPoints;
	this->energyPoints = object.energyPoints;
	this->attackDamage = object.attackDamage;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
		std::cout << "ClapTrap "<< this->name << " attacks " << target << ", causing "<< this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
	else if (energyPoints == 0)
		std::cout << "Low Energy !" << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " is died !" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " taking damage (" << amount << ") " << std::endl;
		hitPoints -= amount;
	}
	else
		std::cout << "ClapTrap " << this->name << " is die!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
        std::cout << "ClapTrap " << this->name << " repairing it self (+" << amount << ") "  << "(!This will cause an energy point!)" << std::endl;
        this->energyPoints--;
        this->hitPoints += amount;
        std::cout << "New Hit Points -> " << this->hitPoints << std::endl;
    }
	else if (this->energyPoints == 0)
		std::cout << "Low Energy !" << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " is die!";
}


std::string ClapTrap::getNm()
{
	return this->name;
}

int	ClapTrap::getHp()
{
	return this->hitPoints;
}

int	ClapTrap::getEp()
{
	return this->energyPoints;
}

int	ClapTrap::getAd()
{
	return this->attackDamage;
}
