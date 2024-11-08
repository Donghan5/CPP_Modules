#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &rightSide) {
	std::cout << "Copy constructor called" << std::endl;
	setRawBits(rightSide.getRawBits());
}

Fixed	&Fixed::operator=(const Fixed &rightSide) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rightSide) {
		this->_fixedPointVal = rightSide.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	return (this->_fixedPointVal);
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedPointVal = raw;
}

int	Fixed::toInt(void) const {

}

float	Fixed::toFloat(void) const {

}
