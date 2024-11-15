#include "Cat.hpp"

Cat::Cat(void): Animal("Cat") {
	std::cout << "Default constructor of " << this->type << " has been called." << std::endl;
	try {
		this->_brain = new Brain();
	}
	catch (std::bad_alloc& e) {
		std::cout << "Memory allocaton failed: " << e.what() << std::endl;
	}
}

Cat::Cat(const Cat &rightSide): Animal(rightSide) {
	std::cout << "Copy constructor of " << this->type << " has been called." << std::endl;
	*this = rightSide;
}

Cat::~Cat(void) {
	std::cout << "Destructor of " << this->type << " has been called." << std::endl;
}

void	Cat::makeSound(void) const {
	std::cout << " * Meow~~~ * " << std::endl;
}
