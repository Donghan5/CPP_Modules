/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:20:39 by donghank          #+#    #+#             */
/*   Updated: 2024/11/30 16:54:16 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*
	Constructor
*/
Cat::Cat(void): Animal("Cat") {
	std::cout << "Default constructor of " << this->type << " has been called." << std::endl;
}

/*
	Copy assignement
*/
Cat::Cat(const Cat &rightSide): Animal(rightSide) {
	std::cout << "Copy constructor of " << this->type << " has been called." << std::endl;
}

/*
	Destructor
*/
Cat::~Cat(void) {
	std::cout << "Destructor of " << this->type << " has been called." << std::endl;
}

/*
	Cat makeSound function
	overload virtual
*/
void	Cat::makeSound(void) const {
	std::cout << "Meow~~" << std::endl;
}
