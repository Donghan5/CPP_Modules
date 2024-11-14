#include "WrongDog.hpp"

WrongDog::WrongDog(void): WrongAnimal("WrongDog") {
	std::cout << "Default constructor of " << this->type << " has been called." << std::endl;
}

WrongDog::WrongDog(const WrongDog &rightSide): WrongAnimal(rightSide) {
	std::cout << "Copy constructor of " << this->type << " has been called." << std::endl;
	*this = rightSide;
}

WrongDog::~WrongDog() {
	std::cout << "Destructor of " << this->type << " has been called." << std::endl;
}

void	WrongDog::makeSound(void) const {
	std::cout << "* Meow(WrongDog sound) *" << std::endl;
}
