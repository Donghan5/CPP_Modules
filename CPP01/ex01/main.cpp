#include "Zombie.hpp"

# define N 42

int	main(void) {
	Zombie	*zombiess = zombieHorde(N, "KING");

	for (int i = 0; i < N; i++) {
		zombiess[i].announce();
		std::cout << "Zombie number " << std::flush; // to verify the index of the zombie horde
		std::cout << i << " is called" << std::endl; // to verify the index of the zombie horde
	}
	delete[] zombiess;
	return (0);
}
