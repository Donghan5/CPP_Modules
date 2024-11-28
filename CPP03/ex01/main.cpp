/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:17:30 by donghank          #+#    #+#             */
/*   Updated: 2024/11/28 18:07:58 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*
	Call constructor
	1. ClapTrap (parent class)
	2. ScavTrap
	Call destructor
	1. ScavTrap
	2. ClapTrap (parent class)
*/
int	main(void) {
	ScavTrap	John("John");
	// ScavTrap	Cole("Cole");

	John.attack("BOB");
	John.attack("Alice");
	John.attack("Vincent");
	John.beRepaired(10);
	John.guradGate();

	// just check assigning operator
	// std::cout << "Assigning Cole to John..." << std::endl;
	// John = Cole;
	return 0;
}
