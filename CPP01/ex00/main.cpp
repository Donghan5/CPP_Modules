/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:12:59 by donghank          #+#    #+#             */
/*   Updated: 2024/11/21 20:13:00 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	std::string	name;

	std::cout << "Creating the zombie on the stack..." << std::endl;
	std::cout << "Zombie name: " << std::flush;
	std::cin >> name;

	Zombie stackZombie(name);

	std::cout << "Creating the zombie on the heap" << std::endl;
	std::cout << "Zombie name: " << std::flush;
	std::cin >> name;

	Zombie	*heapZombie = newZombie(name);
	heapZombie->announce();
	delete heapZombie; // deallocation the pointer of the class obj

	std::cout << "Calling the randomChump..." << std::endl;
	randomChump("randomZombie"); // make new obj in class which name (arg)
	return (0);
}
