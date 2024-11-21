/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:16:34 by donghank          #+#    #+#             */
/*   Updated: 2024/11/21 20:16:35 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	John("John");

	John.attack("BOB");
	John.attack("BOB");
	John.attack("Alice");
	John.attack("Vincent");
	John.takeDamage(10);
	John.beRepaired(10);
	return 0;
}
