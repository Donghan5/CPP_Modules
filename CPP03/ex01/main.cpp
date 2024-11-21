/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:17:30 by donghank          #+#    #+#             */
/*   Updated: 2024/11/21 20:17:31 by donghank         ###   ########.fr       */
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

	John.attack("BOB");
	John.attack("Alice");
	John.attack("Vincent");
	John.beRepaired(10);
	John.guradGate();
	return 0;
}
