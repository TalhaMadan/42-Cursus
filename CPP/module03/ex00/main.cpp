#include "ClapTrap.hpp"

int main(){
	ClapTrap a("Oscar");
	ClapTrap b("Cardozo");


	a.attack("Cardozo");
	b.takeDamage(a.getAd());
	b.beRepaired(3);
	
	b.attack("Oscar");
	a.takeDamage(b.getAd());
	a.beRepaired(20);
}