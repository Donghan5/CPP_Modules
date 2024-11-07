#include "Harl.hpp"

int	main(int argc, char **argv) {
	Harl	Harl;

	if (argc != 2) {
		std::cout << "Make sure amount of argument" << std::endl;
		return (1);
	}
	Harl.complain(argv[1]);
	return (0);
}
