#include "Character.hpp"

Character::Character(): _name("Default") {
	// std::cout << "Default constructor of the Character has been called." << std::endl;
}

Character::Character(const std::string &name): _name(name) {
	// std::cout << "Type constructor of the Character has been called." << std::endl;
}

Character::Character(const Character &rightSide) {
	// std::cout << "Copy-constructor has been called" << std::endl;
	*this = rightSide;
}

Character::~Character() {
	// std::cout << "Destructor of the Character has been called." << std::endl;
}

Character	&Character::operator=(const Character &rightSide) {
	this->_name = rightSide._name;
}
