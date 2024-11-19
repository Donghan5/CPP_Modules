#include "AMateria.hpp"

AMateria::AMateria(std::string const &type): _type(type) {
	std::cout << "Type constructor of AMateria has been called" << std::endl;
}

AMateria::AMateria(const AMateria &rightSide) {
	std::cout << "Copy constructor of AMateria has been called" << std::endl;
	*this = rightSide;
}

AMateria::~AMateria() {
	std::cout << "Destructor of AMateria has been called" << std::endl;
}

AMateria	&AMateria::operator=(const AMateria &rightSide) {
	this->_type = rightSide._type;
}

std::string const	&AMateria::getType(void) const {
	return (this->_type);
}
