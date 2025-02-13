/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:22:51 by donghank          #+#    #+#             */
/*   Updated: 2024/12/10 12:31:38 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

WrongDog::WrongDog(void): WrongAnimal("WrongDog") {
	std::cout << "Default constructor of " << this->type << " has been called." << std::endl;
}

WrongDog::WrongDog(const WrongDog &rightSide): WrongAnimal(rightSide) {
	std::cout << "Copy constructor of " << this->type << " has been called." << std::endl;
}

WrongDog::~WrongDog() {
	std::cout << "Destructor of " << this->type << " has been called." << std::endl;
}

void	WrongDog::makeSound(void) const {
	std::cout << "* Braking bow wow!!! *" << std::endl;
}
