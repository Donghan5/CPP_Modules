#include "Weapon.hpp"

/*
	Constructor
*/
Weapon::Weapon(std::string type) {
	this->setType(type);
}

/*
	Deconstructor
*/
Weapon::~Weapon() {

}

/*
	to get the type of the weapon
*/
const std::string&	Weapon::getType() {
	return (this->type);
}

void	Weapon::setType(std::string newType) {
	this->type = newType;
}
