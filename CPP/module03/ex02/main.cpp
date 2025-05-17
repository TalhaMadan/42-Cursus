#include "FragTrap.hpp"

int main(){
    FragTrap ab("ta");
    FragTrap ba("dil");

    ba.attack("ta");
    ab.takeDamage(ba.getAd());
    ab.beRepaired(ba.getAd());
}