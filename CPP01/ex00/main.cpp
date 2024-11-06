#include "Zombie.hpp"

int	main(void) {
	std::string	name;

	std::cout << "Creating the zombie on the stack..." << std::endl;
	std::cout << "Zombie name: " << std::flush;
	std::cin >> name;

	Zombie stackZombie(name);

	std::cout << "Creating the zombie on the heap" << std::endl;
	std::cout << "Zombie name: " << std::flush;
	std::cin >> name;

	Zombie	*heapZombie = newZombie(name);
	heapZombie->announce();
	delete heapZombie; // deallocation the pointer of the class obj

	std::cout << "Calling the randomChump..." << std::endl;
	randomChump("randomZombie"); // make new obj in class which name (arg)
	return (0);
}
