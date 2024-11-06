#include "Zombie.hpp"

/*
	randomZombie --> new obj
*/
void	randomChump(std::string name) {
	Zombie	randomZombie(name);
	randomZombie.announce();
}
