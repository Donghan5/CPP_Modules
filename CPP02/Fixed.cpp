#include "Fixed.hpp"

/*
	constructor
*/
Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointVal = 0;
}

/*
	copy constructor
*/
Fixed::Fixed(const Fixed &rightSide) {
	std::cout << "Copy constructor called" << std::endl;
	setRawBits(rightSide.getRawBits());
}

/*
	copy assignment operator overload
*/
Fixed	&Fixed::operator=(const Fixed &rightSide) {
	std::cout << "Copy assignment operator called" << std::endl;
	// Check for self-assignment (prevent self-assignment)
	if (this != &rightSide) {
		this->_fixedPointVal = rightSide.getRawBits();
	}
	return (*this);
}

/*
	Destructor
*/
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
}

void	Fixed::setRawBits(int const raw) {

}
