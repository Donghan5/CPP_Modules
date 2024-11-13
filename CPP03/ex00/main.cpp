#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	John("John");

	John.attack("BOB");
	John.attack("BOB");
	John.attack("Alice");
	John.attack("Vincent");
	John.takeDamage(10);
	John.beRepaired(10);
	return 0;
}
