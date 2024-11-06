#include "HumanB.hpp"

/*
	constructor
*/
HumanB::HumanB(std::string name): _name(name) {
	this->_weapon = NULL;
}

/*
	deconstructor
*/
HumanB::~HumanB() {

}

/*
	setter
*/
void	HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}

/*
	attack function
*/
void	HumanB::attack() const {
	if (this->_weapon != NULL && this->_weapon->getType() != "") {
		std::cout << _name << " attack with their " << this->_weapon->getType() << std::endl;
	}
	else
		std::cout << _name << " doesn't have a weapon to attack " << std::endl;
}
