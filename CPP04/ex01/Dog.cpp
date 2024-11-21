/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:22:24 by donghank          #+#    #+#             */
/*   Updated: 2024/11/21 20:22:25 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal("Dog") {
	std::cout << "Default constructor of " << this->type << " has been called." << std::endl;
	try {
		this->_brain = new Brain();
	}
	catch(std::bad_alloc& e) {
		std::cout << "Memory allocation failed: " << e.what() << std::endl;
	}
}

Dog::Dog(const Dog &rightSide): Animal(rightSide), _brain(new Brain(*rightSide._brain)) {
	std::cout << "Copy assignement of " << this->type << " has been called." << std::endl;
}

Dog::~Dog(void) {
	std::cout << "Destructor of " << this->type << " has been called." << std::endl;
	delete _brain;
}

Animal	&Dog::operator=(const Animal &rightSide) {
	const Dog	*other;

	other = dynamic_cast<const Dog *>(&rightSide);
	if (other) {
		std::cout << "Dog operator= has been called" << std::endl;
		this->type = other->type;
		std::cout << "Type copied: " << this->type << "to " << other->type << std::endl;
		*this->_brain = *other->_brain;
	}
	else {
		std::cout << "Dynamic cast failed in Dog" << std::endl;
	}
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << " * Barking bow wow!! * " << std::endl;
}

Brain	*Dog::getBrain(void) const {
	return (this->_brain);
}
