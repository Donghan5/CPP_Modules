#include "ScavTrap.hpp"

/*
	Call constructor
	1. ClapTrap (parent class)
	2. ScavTrap
	Call destructor
	1. ScavTrap
	2. ClapTrap (parent class)
*/
int	main(void) {
	ScavTrap	John("John");

	John.attack("BOB");
	John.attack("Alice");
	John.attack("Vincent");
	return 0;
}
