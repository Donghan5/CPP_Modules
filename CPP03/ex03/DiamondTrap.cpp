#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap() {
	std::cout << "DiamondTrap " << this->_name << " default constructor has been called" << std::endl;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

/*
	The reason to put _clap_name --> to verify it use in the DiamondTrap
*/
DiamondTrap::DiamondTrap(std::string &name): ClapTrap(name), ScavTrap(name), FragTrap(name) {
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &rightSide): ClapTrap(rightSide), ScavTrap(rightSide), FragTrap(rightSide) {
	std::cout << "DiamondTrap " << this->_name << " Assignement has been called." << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap desturctor has been called." << std::endl;
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "DiamondTrap name: " << this->_name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}
