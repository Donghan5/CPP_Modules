#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat") {
	std::cout << "Default constructor of " << this->type << " has been called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &rightSide): WrongAnimal(rightSide) {
	std::cout << "Copy Constructor of " << this->type << " has been called." << std::endl;
	*this = rightSide;
}

WrongCat::~WrongCat() {
	std::cout << "Destructor of " << this->type << " has been called." << std::endl;
}

void	WrongCat::makeSound(void) const {
	std::cout << "* Barking bow wow (WrongCat) *" << std::endl;
}
