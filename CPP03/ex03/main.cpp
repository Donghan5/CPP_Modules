#include "DiamondTrap.hpp"

/*
	Call constructor
	1. ClapTrap (parent class)
	2. ScavTrap / FragTrap
	3. DiamondTrap
	Call destructor
	1. DiamondTrap
	2. ScavTrap / FragTrap
	3. ClapTrap (parent class)
*/
int	main(void) {
	DiamondTrap	John("John");

	John.attack("BOB");
	John.attack("Alice");
	John.attack("Vincent");
	John.beRepaired(10);
	John.takeDamage(10);
	John.guradGate();
	John.highFiveGuys();
	return 0;
}
