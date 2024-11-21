/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:20:39 by donghank          #+#    #+#             */
/*   Updated: 2024/11/21 20:20:40 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal("Cat") {
	std::cout << "Default constructor of " << this->type << " has been called." << std::endl;
}

Cat::Cat(const Cat &rightSide): Animal(rightSide) {
	std::cout << "Copy constructor of " << this->type << " has been called." << std::endl;
	*this = rightSide;
}

Cat::~Cat(void) {
	std::cout << "Destructor of " << this->type << " has been called." << std::endl;
}

void	Cat::makeSound(void) const {
	std::cout << "Meow~~ (Cats do not bark!!)" << std::endl;
}
