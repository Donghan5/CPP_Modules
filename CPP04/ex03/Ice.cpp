#include "Ice.hpp"

Ice::Ice() {
	std::cout << "Default constructor has been called" << std::endl;
}

Ice::Ice(const Ice &rightSide) {
	std::cout << "Copy constructor has been called" << std::endl;
	*this = rightSide;
}

Ice::~Ice() {
	std::cout << "Destructor has been called" << std::endl;
}

const Ice	&Ice::operator=(const Ice &rightSide) {

}
