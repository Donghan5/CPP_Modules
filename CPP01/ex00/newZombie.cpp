#include "Zombie.hpp"

Zombie	*newZombie(std::string name) {
	Zombie	*zptr = new Zombie(name);
	return (zptr);
}
