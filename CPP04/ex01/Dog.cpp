#include "Dog.hpp"

Dog::Dog(void): Animal("Dog") {
	std::cout << "Default constructor of " << this->type << " has been called." << std::endl;
	try {
		this->_brain = new Brain();
	}
	catch(std::bad_alloc& e) {
		std::cout << "Memory allocation failed: " << e.what() << std::endl;
	}
}

Dog::Dog(const Dog &rightSide): Animal(rightSide) {
	std::cout << "Copy assignement of " << this->type << " has been called." << std::endl;
	*this = rightSide;
}

Dog::~Dog(void) {
	std::cout << "Destructor of " << this->type << " has been called." << std::endl;
}

void	Dog::makeSound(void) const {
	std::cout << " * Barking bow wow!! * " << std::endl;
}
