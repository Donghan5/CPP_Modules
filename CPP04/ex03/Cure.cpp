#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {
	// std::cout << "Default constructor has been called" << std::endl;
}

Cure::Cure(const Cure &rightSide): AMateria("cure") {
	// std::cout << "Copy constructor has been called" << std::endl;
	*this = rightSide;
}

Cure::~Cure() {
	// std::cout << "Destructor has been called" << std::endl;
}

Cure	&Cure::operator=(const Cure &rightSide) {
	this->_type = rightSide._type;
	return (*this);
}

AMateria	*Cure::clone(void) const {
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
