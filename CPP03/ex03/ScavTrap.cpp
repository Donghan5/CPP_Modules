#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	this->_name = "scav";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " constructed." << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->_name << " destructed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &rightSide): ClapTrap(rightSide) {
	std::cout << "ScavTrap " << this->_name << " Copy consturctor called." << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &rightSide) {
	std::cout << "ScavTrap " << this->_name << " Assignement called" << std::endl;
	ClapTrap::operator=(rightSide);
	return *this;
}

void	ScavTrap::attack(const std::string &target) {
	if (_energyPoints <= 0) {
		std::cout << "ScavTrap " << this->_name << " have no more energy" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints -= 1;
}

void	ScavTrap::guradGate(void) {
	std::cout << "ScavTrap " << this->_name << " is in mode Gate Keeper" << std::endl;
}
