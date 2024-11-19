#include "Cure.hpp"

Cure::Cure() {
	std::cout << "Default constructor has been called" << std::endl;
}

Cure::Cure(const Cure &rightSide) {
	std::cout << "Copy constructor has been called" << std::endl;
	*this = rightSide;
}

Cure::~Cure() {
	std::cout << "Destructor has been called" << std::endl;
}

Cure	&Cure::operator=(const Cure &rightSide) {

}
