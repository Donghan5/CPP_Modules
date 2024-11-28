/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:20:01 by donghank          #+#    #+#             */
/*   Updated: 2024/11/28 18:12:21 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*
	Call constructor
	1. ClapTrap (parent class)
	2. ScavTrap / FragTrap
	3. DiamondTrap
	Call destructor
	1. DiamondTrap
	2. ScavTrap / FragTrap
	3. ClapTrap (parent class)
*/
int	main(void) {
	DiamondTrap	John("John");
	DiamondTrap	Cole("Cole");

	John.attack("BOB");
	John.attack("Alice");
	John.attack("Vincent");
	John.beRepaired(10);
	John.takeDamage(10);
	John.guradGate();
	John.highFiveGuys();
	John.whoAmI();

	// Just to check assigning operator
	// std::cout << "Assigning Cole to John" << std::endl;
	// John = Cole;
	return 0;
}
