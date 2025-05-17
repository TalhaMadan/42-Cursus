#include "ScavTrap.hpp"

int main(){
    ScavTrap ab("tm");
    ScavTrap ba("dk");

    ba.attack("tm");
    ab.takeDamage(ba.getAd());
    ab.beRepaired(ba.getAd());
}