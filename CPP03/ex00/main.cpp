/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:16:34 by donghank          #+#    #+#             */
/*   Updated: 2024/11/28 18:09:03 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	John("John");
	// ClapTrap	Cole("Cole");

	John.attack("BOB");
	John.attack("BOB");
	John.attack("Alice");
	John.attack("Vincent");
	John.takeDamage(10);
	John.beRepaired(10);

	// just to check assigning operator
	// std::cout << "Assigning Cole to John" << std::endl;
	// John = Cole;
	return 0;
}
