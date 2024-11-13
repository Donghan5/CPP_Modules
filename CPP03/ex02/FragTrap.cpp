#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "FragTrap " << this->_name << " default constructor has been called." << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 20;
	std::cout << "FragTrap " << this->_name << " constructed." << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->_name << " destructed." << std::endl;
}

FragTrap::FragTrap(const FragTrap &rightSide): ClapTrap(rightSide) {
	std::cout << "FragTrap " << this->_name << " Copy constructor has been called." << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &rightSide) {
	std::cout << "FragTrap " << this->_name << " Assignement has been called." << std::endl;
	ClapTrap::operator=(rightSide);
	return *this;
}

void	FragTrap::attack(const std::string &target) {
	if (_energyPoints <= 0) {
		std::cout << "FragTrap " << this->_name << " have no more energy" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints -= 1;
}

void	FragTrap::highFiveGuys(void) {
	std::cout << "FragTrap " << this->_name << " highfive, keep going guys!" << std::endl;
}
